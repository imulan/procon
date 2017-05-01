#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pl = pair<ll,ll>;

struct LazySegTree{
    int n;
    vector<ll> lazy;
    vector<pl> dat;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pl>(2*n-1,pl(0,0));
        lazy=vector<ll>(2*n-1,0);
    }

    void setLazy(int k, ll v, int l, int r){
        lazy[k] = v;
        if(v==1) dat[k] = pl(r-l,0);
        else dat[k] = pl(0,r-l);
    }

    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k],l,(l+r)/2);
            setLazy(2*k+2,lazy[k],(l+r)/2,r);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        dat[k]=merge(dat[2*k+1],dat[2*k+2]);
    }

    pl merge(pl x, pl y){
        return pl(x.fi+y.fi, x.se+y.se);
    }

    //内部的に投げられるクエリ
    void _update(int a, int b, ll x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,x,l,r);
            return;
        }

        push(k,l,r);
        _update(a,b,x,2*k+1,l,(l+r)/2);
        _update(a,b,x,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)をx
    void update(int a, int b, ll x){
        return _update(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    pl _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return pl(0,0);
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        pl vl=_query(a,b,2*k+1,l,(l+r)/2);
        pl vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)
    pl query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,Q;
    scanf(" %d %d", &n, &Q);

    ll a=0,b=0;
    LazySegTree st(n);
    while(Q--)
    {
        int x,l,r;
        scanf(" %d %d %d", &x, &l, &r);
        if(x==0)
        {
            pl p = st.query(l,r+1);
            if(p.fi>p.se) a+=p.fi;
            else if(p.fi<p.se) b+=p.se;
        }
        else st.update(l,r+1,x);
    }

    pl res = st.query(0,n);
    a+=res.fi;
    b+=res.se;

    printf("%lld %lld\n", a,b);
    return 0;
}
