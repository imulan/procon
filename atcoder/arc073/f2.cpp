#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = LLONG_MAX/3;

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
        if(r<=a || b<=l) return LLONG_MAX/2;
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

int main()
{
    int n,Q,A,B;
    scanf(" %d %d %d %d", &n, &Q, &A, &B);
    --A;
    --B;

    vector<int> x(Q+1);
    rep(i,Q)
    {
        scanf(" %d", &x[i+1]);
        --x[i+1];
    }
    x[0]=B;

    LazySegTree L(n),R(n);
    L.add(0,A,INF);
    L.add(A,A+1,-A);
    L.add(A+1,n,INF);
    R.add(0,A,INF);
    R.add(A,A+1,A);
    R.add(A+1,n,INF);

    rep(i,Q)
    {
        ll v = min(L.query(0,x[i+1]+1)+x[i+1], R.query(x[i+1],n)-x[i+1]);

        ll d = abs(x[i+1]-x[i]);
        L.add(0,n,d);
        R.add(0,n,d);

        ll vl = L.query(x[i],x[i]+1)+x[i];

        if(v<vl)
        {
            ll ml=L.query(x[i],x[i]+1), mr=R.query(x[i],x[i]+1);

            L.add(x[i],x[i]+1,-ml);
            R.add(x[i],x[i]+1,-mr);

            assert(L.query(x[i],x[i]+1)==0);

            L.add(x[i],x[i]+1,v-x[i]);
            R.add(x[i],x[i]+1,v+x[i]);
        }
    }

    ll ans = INF;
    rep(i,n) ans=min(ans,L.query(i,i+1)+i);
    printf("%lld\n", ans);
    return 0;
}
