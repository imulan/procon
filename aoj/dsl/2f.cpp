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
        lazy=vector<ll>(2*n-1,INF);
    }

    void show()
    {
        rep(j,dat.size()) printf(" %d: dat= %lld, lazy= %lld\n", j,dat[j],lazy[j]);
    }

    void setLazy(int k, ll v){
        lazy[k] = v;
        dat[k] = v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=INF){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=INF;
    }

    void fix(int k, int l, int r){
        dat[k]=min(dat[2*k+1],dat[2*k+2]);
    }

    ll merge(ll x, ll y){
        return min(x,y);
    }

    //内部的に投げられるクエリ
    void _update(int a, int b, ll x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,x);
            return;
        }

        push(k,l,r);
        _update(a,b,x,2*k+1,l,(l+r)/2);
        _update(a,b,x,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)にx
    void update(int a, int b, ll x){
        return _update(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;
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
    int n,q;
    scanf(" %d %d", &n, &q);

    LazySegTree st(n);
    st.update(0,n,(1LL<<31)-1);

    while(q--)
    {
        int ord,s,t;
        scanf(" %d %d %d", &ord, &s, &t);
        if(ord==0)
        {
            ll x;
            scanf(" %lld", &x);
            st.update(s,t+1,x);
        }
        else
        {
            printf("%lld\n", st.query(s,t+1));
        }
    }

    return 0;
}
