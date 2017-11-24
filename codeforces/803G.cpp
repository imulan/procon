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

struct LazySegTree{
    int n; vector<ll> dat,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MAX/2);
        lazy=vector<ll>(2*n-1,0);
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
    int n,k;
    cin >>n >>k;
    vector<int> b(n);
    rep(i,n) cin >>b[i];

    int q;
    cin >>q;
    vector<int> t(q), l(q), r(q), x(q,-1);
    rep(i,q)
    {
        cin >>t[i] >>l[i] >>r[i];
        --l[i];
        --r[i];
        if(t[i]==1) cin >>x[i];
    }

    vector<int> idx;
    rep(i,q)
    {
        idx.pb(l[i]);
        idx.pb(r[i]);
    }
    idx.pb(0);
    idx.pb(n*k-1);
    sort(all(idx));
    idx.erase(unique(all(idx)), idx.end());

    LazySegTree one(n);
    rep(i,n) one.update(i,i+1,b[i]);

    map<int,int> m;
    vector<int> comp;
    comp.pb(b[0]);
    m[0] = 0;
    for(int i=1; i<idx.size(); ++i)
    {
        if(idx[i]-idx[i-1]>1)
        {
            int L=(idx[i-1]+1)%n, R=(idx[i]+n-1)%n;
            int v;
            if(L<=R) v = one.query(L,R+1);
            else v = min(one.query(0,R+1),one.query(L,n));
            comp.pb(v);
        }

        m[idx[i]] = comp.size();
        comp.pb(b[idx[i]%n]);
    }

    LazySegTree st(comp.size());
    rep(i,comp.size()) st.update(i,i+1,comp[i]);

    rep(i,q)
    {
        int L=m[l[i]], R=m[r[i]];
        if(t[i]==1) st.update(L,R+1,x[i]);
        else cout << st.query(L,R+1) << endl;
    }
    return 0;
}
