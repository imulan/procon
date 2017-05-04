#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pl = pair<ll,ll>;
using P = pair<pl,ll>;

struct LazySegTree{
    int n;
    vector<ll> lazy;
    // ((左端、右端),差のgcd)
    vector<P> dat;
    //初期化
    LazySegTree(int _n, const vector<ll> &a){
        n=1;
        while(n<_n) n*=2;
        dat=vector<P>(2*n-1,P(pl(0,0),0));
        lazy=vector<ll>(2*n-1,0);

        rep(i,a.size()) dat[i+n-1] = P(pl(a[i],a[i]),0);
        for(int i=n-2; i>=0; --i)
        {
            int l=2*i+1, r=2*i+2;
            dat[i] = P(pl(dat[l].fi.fi,dat[r].fi.se), __gcd(abs(dat[l].fi.se-dat[r].fi.fi),__gcd(dat[l].se,dat[r].se)));
        }
    }

    void show()
    {
        rep(i,2*n-1) printf("dat[ %d]= ( (%lld,%lld), %lld )\n", i,dat[i].fi.fi,dat[i].fi.se,dat[i].se);

    }

    void setLazy(int k, ll v){
        lazy[k] += v;
        dat[k].fi.fi += v;
        dat[k].fi.se += v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=0;
    }

    void fix(int k){
        int l=2*k+1, r=2*k+2;
        dat[k]=P(pl(dat[l].fi.fi,dat[r].fi.se), __gcd(abs(dat[l].fi.se-dat[r].fi.fi),__gcd(dat[l].se,dat[r].se)));
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

        fix(k);
    }
    //[a,b)に+x
    void add(int a, int b, ll x){
        return _add(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    P _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return P(pl(0,0),0);
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        P vl=_query(a,b,2*k+1,l,(l+r)/2);
        P vr=_query(a,b,2*k+2,(l+r)/2,r);

        P ret;
        ret.fi = pl(vl.fi.fi,vr.fi.se);
        ret.se = __gcd(abs(vl.fi.se-vr.fi.fi),__gcd(vl.se,vr.se));

        return ret;
    }
    //[a,b)
    P query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    LazySegTree st(n,a);

    int m;
    scanf(" %d", &m);
    while(m--)
    {
        ll t;
        int l,r;
        scanf(" %lld %d %d", &t, &l, &r);
        --l;
        --r;
        if(t==0)
        {
            P p=st.query(l,r+1);
            printf("%lld\n", __gcd(p.fi.fi,p.se));
        }
        else st.add(l,r+1,t);
    }

    return 0;
}
