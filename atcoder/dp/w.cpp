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

// 区間add, 区間max
struct LazySegTree{
    int n; vector<ll> dat,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,-INF);
        lazy=vector<ll>(2*n-1,0);
    }
    void setLazy(int k, ll v){
        lazy[k] += v;
        dat[k] += v;
    }
    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=0;
    }
    void fix(int k, int l, int r){
        dat[k]=max(dat[2*k+1],dat[2*k+2]);
    }
    ll merge(ll x, ll y){
        return max(x,y);
    }
    //内部的に投げられるクエリ
    void _add(int a, int b, ll x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,x);
            return;
        }

        push(k,l,r);
        _add(a,b,x,2*k+1,l,(l+r)/2);
        _add(a,b,x,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)に+x
    void add(int a, int b, ll x){
        return _add(a,b,x,0,0,n);
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return -INF;
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<pair<int,int>>> L(n+1),R(n+1);
    rep(i,m){
        int l,r,a;
        scanf(" %d %d %d", &l, &r, &a);
        L[l].pb({l,a});
        R[r].pb({l,a});
    }

    LazySegTree st(n+1);
    vector<ll> dp(n+1,-INF);
    dp[0] = 0;
    st.add(0, 1, INF);

    for(int i=1; i<=n; ++i){
        for(const auto &p:L[i]) st.add(0, p.fi, p.se);

        dp[i] = st.query(0,i);
        st.add(i, i+1, dp[i]+INF);

        for(const auto &p:R[i]) st.add(0, p.fi, -p.se);
    }

    printf("%lld\n", *max_element(all(dp)));
    return 0;
}
