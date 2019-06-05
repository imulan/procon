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

const int INF = 1010101;

struct MaxSegTree{
    int n; vector<ll> dat;
    // 初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    // [a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

using pi = pair<int,int>;

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> x(n);
    vector<int> dp(n+2, INF);
    dp[0] = -1;
    rep(i,n){
        int idx = lower_bound(all(dp), a[i]) - dp.begin();
        dp[idx] = a[i];
        x[i] = idx;
    }

    int L = 0;
    while(dp[L]<INF) ++L;
    --L;

    vector<vector<int>> v(L+1);
    rep(i,n) v[x[i]].pb(i);

    MaxSegTree st(n);

    unordered_map<int,ll> pre;
    rep(i,n)if(x[i]==1) pre[i] = a[i];
    for(int i=2; i<=L; ++i){
        vector<pi> p;
        for(int j:v[i-1]) p.pb({a[j],j});
        sort(all(p));

        int P = p.size();
        int pidx = 0;

        vector<pi> now;
        unordered_map<int,ll> nx;
        for(int j:v[i]) now.pb({a[j],j});
        sort(all(now));

        for(const auto &pp:now){
            int idx = pp.se;
            while(pidx<P && p[pidx].fi<pp.fi){
                st.update(p[pidx].se, pre[p[pidx].se]);
                ++pidx;
            }

            ll val = st.query(0,idx);
            nx[idx] = val+a[idx];
        }

        for(const auto &pp:p) st.update(pp.se, 0);

        pre = nx;
    }

    ll ans = 0;
    for(const auto &pp:pre) ans = max(ans, pp.se);
    printf("%lld\n", ans);
    return 0;
}
