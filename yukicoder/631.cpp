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
        if(r<=a || b<=l) return LLONG_MIN/3;
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
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<ll> t(n-1);
    rep(i,n-1) cin >>t[i];

    LazySegTree T(n-1);
    ll a=3;
    for(int i=n-2; i>=0; --i){
        T.add(i,i+1,t[i]+a);
        a+=3;
    }

    int m;
    cin >>m;
    while(m--){
        int l,r,d;
        cin >>l >>r >>d;
        --l;
        --r;
        T.add(l,r+1,d);
        cout << T.query(0,n) << endl;
    }
    return 0;
}
