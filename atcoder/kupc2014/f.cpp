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

const int N = 1001;
const ll INF = LLONG_MAX/3;

int n;
int x[N],y[N],d[N],c[N];

inline ll sq(ll a){ return a*a; }
inline ll dist2(int a, int b){ return sq(x[a]-x[b]) + sq(y[a]-y[b]); }

vector<int> G[N];

int query(int v, int r, int nx)
{
    int L=-1, R=2849;
    while(R-L>1)
    {
        int m = (L+R)/2;
        if( sq(d[v]+r+d[nx]+m) >= dist2(v,nx) ) R=m;
        else L=m;
    }
    return R;
}

ll dp[N][2850];
int par[N];
// 今vにいる、最小強化幅r
ll dfs(int v, int r)
{
    if(dp[v][r]>=0) return dp[v][r];

    ll ret = c[v]*r;
    for(int nx:G[v])if(nx!=par[v])
    {
        par[nx] = v;
        ret += dfs(nx,query(v,r,nx));
    }

    if(d[v]+r+1<2850) ret = min(ret, dfs(v,r+1));
    return dp[v][r] = ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>x[i] >>y[i];
    rep(i,n) cin >>d[i] >>c[i];

    rep(i,n-1)
    {
        int u,v;
        cin >>u >>v;
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    memset(dp,-1,sizeof(dp));
    memset(par,-1,sizeof(par));
    cout << dfs(0,0) << endl;
    return 0;
}
