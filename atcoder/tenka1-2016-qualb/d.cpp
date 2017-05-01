#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using P = pair<pi,int>;

// 区間add, 区間min
struct LazySegTree{
    int n; vector<ll> dat,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
        lazy=vector<ll>(2*n-1,0);
    }

    void show()
    {
        rep(j,dat.size()) printf(" %d: dat= %lld, lazy= %lld\n", j,dat[j],lazy[j]);
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
        dat[k]=min(dat[2*k+1],dat[2*k+2]);
    }

    ll merge(ll x, ll y){
        return min(x,y);
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
        if(r<=a || b<=l) return LLONG_MAX/3;
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)の最小値
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N=100000;

//(値, 時刻)
vector<pi> L[N],R[N];
vector<P> Q[N];

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int A;
    scanf(" %d", &A);
    rep(i,A)
    {
        int l,r,x;
        scanf(" %d %d %d", &l, &r, &x);
        --l;
        --r;

        L[l].pb(pi(x,i));
        R[r].pb(pi(x,i));
    }

    int B;
    scanf(" %d", &B);
    rep(i,B)
    {
        int s,t,k;
        scanf(" %d %d %d", &s, &t, &k);
        --s;
        --t;
        --k;
        Q[k].pb(P(pi(s,t),i));
    }

    LazySegTree st(A+1);
    vector<ll> ans(B);

    rep(i,n)
    {
        st.add(0,A+1,a[i]);
        for(const auto &p:L[i]) st.add(p.se+1,A+1,p.fi);

        for(const auto &q:Q[i])
        {
            int s=q.fi.fi, t=q.fi.se, idx=q.se;
            ans[idx] = st.query(s,t+2);
        }

        for(const auto &p:R[i]) st.add(p.se+1,A+1,-p.fi);
        st.add(0,A+1,-a[i]);
    }

    rep(i,B) printf("%lld\n", ans[i]);
    return 0;
}
