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

// range add, range max
struct LazySegTree{
    int n; vector<ll> dat,lazy;
    LazySegTree(){}
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
    //[a,b) +x
    void add(int a, int b, ll x){
        return _add(a,b,x,0,0,n);
    }

    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MIN/2;
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b) max
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

using pi = pair<int,int>;
using P = pair<pi,int>;

int cv(char c)
{
    if(c=='E' || c=='C') return 0;
    return 1;
}

const int N = 50000;
vector<int> range[N][2];

const int INF = 19191919;

void solve2()
{
    rep(i,N)rep(j,2) range[i][j].clear();

    int m,n;
    scanf(" %d %d", &m, &n);

    vector<int> t(n),s(n),d(n);
    rep(i,n)
    {
        char c;
        scanf(" %c", &c);
        t[i] = cv(c);
    }
    rep(i,n)
    {
        scanf(" %d", &s[i]);
        --s[i];
    }
    rep(i,n)
    {
        scanf(" %d", &d[i]);
        --d[i];
    }

    rep(i,n)if(s[i]<d[i]) range[d[i]][t[i]].pb(s[i]);

    vector<int> ans(n,INF);

    LazySegTree dp[2];
    rep(i,2) dp[i] = LazySegTree(m);

    rep(i,m)
    {
        rep(j,2)for(int idx:range[i][j]) dp[!j].add(0,idx+1,1);

        int v[2];
        rep(j,2) v[j] = dp[!j].query(0,i);

        rep(j,2) dp[j].add(i,i+1,v[j]);

        // dbg(i);
        // printf(" %d %d\n", v[0],v[1]);
        int max_v = max(v[0],v[1]);
        if(max_v>0) ans[max_v-1] = min(ans[max_v-1],i+1);
    }

    for(int i=n-1; i>0; --i) ans[i-1]=min(ans[i-1],ans[i]);
    rep(i,n)if(ans[i]==INF) ans[i]=-1;
    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve2();
    return 0;
}
