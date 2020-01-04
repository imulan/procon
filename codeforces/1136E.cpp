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

const ll INF = LLONG_MAX/3;

struct LazySegTree{
    int n; vector<ll> sum,mx,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        sum=vector<ll>(2*n-1,0);
        mx=vector<ll>(2*n-1,0);
        lazy=vector<ll>(2*n-1,-INF);
    }
    void setLazy(int k, int l, int r, ll v){
        lazy[k] = v;
        sum[k] = v*(r-l);
        mx[k] = v;
    }
    void push(int k, int l, int r){
        if(lazy[k] != -INF){
            setLazy(2*k+1, l, (l+r)/2, lazy[k]);
            setLazy(2*k+2, (l+r)/2, r, lazy[k]);
        }
        lazy[k] = -INF;
    }
    void fix(int k, int l, int r){
        sum[k] = sum[2*k+1]+sum[2*k+2];
        mx[k] = max(mx[2*k+1],mx[2*k+2]);
    }
    ll merge(ll x, ll y){
        return x+y;
    }

    //内部的に投げられるクエリ
    void _update(int a, int b, ll x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,l,r,x);
            return;
        }

        push(k,l,r);
        _update(a,b,x,2*k+1,l,(l+r)/2);
        _update(a,b,x,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)
    void update(int a, int b, ll x){
        return _update(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return sum[k];

        push(k,l,r);
        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }

    int _find(ll v, int k, int l, int r){
        if(k >= n-1) return k;

        push(k,l,r);
        fix(k,l,r);

        if(mx[2*k+1] >= v) return _find(v,2*k+1,l,(l+r)/2);
        return _find(v,2*k+2,(l+r)/2,r);
    }

    int find_idx(ll val){
        return _find(val,0,0,n)-(n-1);
    }
};


int main(){
    int n;
    scanf(" %d", &n);

    vector<ll> a(n),k(n-1);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,n-1) scanf(" %lld", &k[i]);

    vector<ll> t(n),b(n);
    rep(i,n-1) t[i+1] = t[i]+k[i];
    rep(i,n) b[i] = a[i] - t[i];

    vector<ll> pt(n+1);
    rep(i,n) pt[i+1] = pt[i]+t[i];

    LazySegTree st(n+1);
    rep(i,n) st.update(i,i+1,b[i]);
    st.update(n,n+1,INF);

    int q;
    scanf(" %d", &q);
    while(q--){
        char c;
        int x,y;
        scanf(" %c %d %d", &c, &x, &y);
        if(c=='+'){
            --x;

            ll new_b = st.query(x,x+1) + y;
            int pos = st.find_idx(new_b);
            st.update(x,pos,new_b);
        }
        else{
            --x;
            --y;

            ll ans = pt[y+1]-pt[x];
            ans += st.query(x,y+1);

            printf("%lld\n", ans);
        }
    }

    return 0;
}
