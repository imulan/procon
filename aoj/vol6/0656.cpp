#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const ll INF = LLONG_MAX/3;

struct MaxSegTree{
    int n; vector<ll> dat;
    //初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MIN);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MIN;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> a(n+1);
    rep(i,n) scanf(" %d", &a[i+1]);

    vector<vector<int>> L(n+1), R(n+1);
    rep(i,m){
        int l,r;
        scanf(" %d %d", &l, &r);
        L[l].pb(l);
        R[r].pb(l);
    }

    vector<ll> dp(n+1,-INF);
    MaxSegTree st(n+1);

    dp[0] = 0;
    st.update(0, dp[0]);

    multiset<int> s;
    for(int i=1; i<=n; ++i){
        for(int j:L[i]) s.insert(j);

        int idx = i;
        if(!s.empty()) idx = *s.begin();

        dp[i] = st.query(0, idx) + a[i];
        st.update(i, dp[i]);

        for(int j:R[i]) s.erase(s.find(j));
    }

    printf("%lld\n", *max_element(all(dp)));
    return 0;
}
