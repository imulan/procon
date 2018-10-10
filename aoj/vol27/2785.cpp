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

// 区間add, 区間min
struct LazySegTree{
    int n; vector<ll> mx,mn,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        mx=vector<ll>(2*n-1,0);
        mn=vector<ll>(2*n-1,0);
        lazy=vector<ll>(2*n-1,0);
    }

    void setLazy(int k, ll v){
        lazy[k] += v;
        mx[k] += v;
        mn[k] += v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        mx[k] = max(mx[2*k+1], mx[2*k+2]);
        mn[k] = min(mn[2*k+1], mn[2*k+2]);
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
    ll _MIN(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MAX/3;
        if(a<=l && r<=b) return mn[k];

        push(k,l,r);
        ll vl=_MIN(a,b,2*k+1,l,(l+r)/2);
        ll vr=_MIN(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)の最小値
    ll MIN(int a, int b){
        return _MIN(a,b,0,0,n);
    }

        //内部的に投げられるクエリ
    ll _MAX(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return -LLONG_MAX/3;
        if(a<=l && r<=b) return mx[k];

        push(k,l,r);
        ll vl=_MAX(a,b,2*k+1,l,(l+r)/2);
        ll vr=_MAX(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最小値
    ll MAX(int a, int b){
        return _MAX(a,b,0,0,n);
    }
};

const int INF = 1234567;
using P = pair<ll,int>;

int main(){
    int n;
    ll L;
    scanf(" %d %lld", &n, &L);

    vector<ll> a(n),b(n);
    rep(i,n) scanf(" %lld %lld", &a[i], &b[i]);

    vector<ll> c(n);
    rep(i,n) scanf(" %lld", &c[i]);

    rep(i,n-1) c[i+1] += c[i];

    vector<P> drink(n);
    vector<ll> v(n);
    rep(i,n) drink[i] = {a[i]-b[i], i};
    sort(all(drink), greater<P>());

    rep(i,n) v[i] = drink[i].fi;
    rep(i,n-1) v[i+1] += v[i];

    LazySegTree vst(n),st1(n),st2(n);
    rep(i,n){
        vst.add(i,i+1,v[i]);
        st1.add(i,i+1,v[i]);
        st2.add(i,i+1,v[i]);
    }
    rep(i,n) st1.add(i,i+1,-c[i]);
    rep(i,n-1) st2.add(i+1,i+2,-c[i]);

    int ans = INF;
    rep(i,n){
        int idx = drink[i].se;
        ll A = a[idx];
        if(A >= L){
            ans = 1;
            break;
        }
        // dbg(L-A);

        vst.add(i,n+1,-drink[i].fi);

        int ng=-1, ok=n;
        while(ok-ng>1){
            int mid = (ok+ng)/2;
            if(vst.MAX(0,mid+1) >= L-A) ok = mid;
            else ng = mid;
        }

        vst.add(i,n+1,drink[i].fi);
        if(ok == n) continue;

        st1.add(i,n+1,-drink[i].fi);
        st2.add(i,n+1,-drink[i].fi);

        int days;
        if(ok<i){
            days = ok+1 + 1;
            if(st1.MIN(0,ok+1)>0) ans = min(ans,days);
        }
        else{
            days = ok + 1;
            if(st1.MIN(0,i)>0 && st2.MIN(i+1,ok+1)>0) ans = min(ans,days);
        }

        st1.add(i,n+1,drink[i].fi);
        st2.add(i,n+1,drink[i].fi);
    }

    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}
