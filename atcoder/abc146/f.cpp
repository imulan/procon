#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int INF = 19191919;

struct SegTree{
    int n; vector<ll> dat;
    // 初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,INF);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    // [a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

vector<int> solve(){
    int n,m;
    string s;
    cin >>n >>m >>s;

    vector<ll> d(n+1,INF);
    d[n] = 0;
    SegTree st(n+1);
    st.update(n, 0);
    for(int i=n-1; i>=0; --i)if(s[i] == '0'){
        ll md = st.query(i+1, i+m+1);
        d[i] = min(d[i], md+1);
        st.update(i,d[i]);
    }
    if(d[0]>=INF) return vector<int>(1,-1);

    int V = d[0];
    vector<int> ans(V);

    vector<int> pos(V+1);
    for(int i=n; i>=0; --i)if(d[i]<=V) pos[d[i]] = i;
    reverse(all(pos));

    rep(i,V) ans[i] = pos[i+1] - pos[i];
    return ans;
}

int main(){
    vector<int> a = solve();
    int n = a.size();
    rep(i,n) cout << a[i] << " \n"[i==n-1];
    return 0;
}
