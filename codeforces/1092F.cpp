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

const int N = 200002;
int n;
ll a[N];

vector<int> G[N];

ll sz[N];
int par[N];
int dep[N];

void calc_sz(int x, int p){
    par[x] = p;

    sz[x] = a[x];
    for(int e:G[x])if(e!=p){
        dep[e] = dep[x]+1;
        calc_sz(e,x);
        sz[x] += sz[e];
    }
}

ll ans = 0;
void dfs(int x, ll val, ll p){
    ans = max(ans, val);
    // dbg(x); dbg(val);

    ll psz = p+a[x];
    for(int e:G[x])if(e!=par[x]) psz += sz[e];

    for(int e:G[x])if(e!=par[x]){
        psz -= sz[e];
        dfs(e, val+psz-sz[e], psz);
        psz += sz[e];
    }
}

int main(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %lld", &a[i]);

    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dep[0] = 0;
    calc_sz(0,-1);

    rep(i,n) ans += a[i]*dep[i];
    dfs(0,ans,0);

    printf("%lld\n", ans);
    return 0;
}
