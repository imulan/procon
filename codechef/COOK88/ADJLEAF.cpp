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

const ll mod = 1e9+7;
const int N = 300003;
ll pw[N];

inline ll mod_pow(ll x, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

const ll MOD_INV = mod_inv(2);

vector<vector<int>> G;
vector<ll> ans;
vector<vector<ll>> dp;

void dfs(int x, int p)
{
    int C = 0;
    for(int nx:G[x])if(nx!=p)
    {
        dfs(nx,x);
        ++C;
        // children
        rep(i,2) (dp[x][i] += dp[nx][i]) %= mod;
    }

    // cond.1
    if(C>0)rep(i,2) (dp[x][i] += pw[C]-2+mod) %= mod;

    if(C>1)
    {
        ll s = 0;
        ll d = 0;
        for(int nx:G[x])if(nx!=p)
        {
            // cond.2
            rep(i,2) (dp[x][i] += dp[nx][1]*(pw[C-1]-1)) %= mod;

            (s += dp[nx][1]) %= mod;
            (d += dp[nx][1]*dp[nx][1]) %= mod;
        }

        // cond.3
        s = (s*s-d+mod)%mod;
        (s *= MOD_INV) %= mod;
        (s *= pw[C-2])%=mod;
        (dp[x][0] += s) %= mod;
    }
}

void dfs2(int x, int p, ll dp0, ll dp1)
{
    ans[x] = dp0+1;

    int C = (p!=-1);
    for(int nx:G[x])if(nx!=p)
    {
        ++C;
        // children
        (ans[x] += dp[nx][0]) %= mod;
    }

    // cond.1
    if(C>0) (ans[x] += pw[C]-2+mod) %= mod;

    if(C>1)
    {
        ll s = dp1;
        ll d = (dp1*dp1)%mod;

        // cond.2
        (ans[x] += dp1*(pw[C-1]-1)) %= mod;
        for(int nx:G[x])if(nx!=p)
        {
            // cond.2
            (ans[x] += dp[nx][1]*(pw[C-1]-1)) %= mod;

            (s += dp[nx][1]) %= mod;
            (d += dp[nx][1]*dp[nx][1]) %= mod;
        }

        // cond.3
        s = (s*s-d+mod)%mod;
        (s *= MOD_INV) %= mod;
        (s *= pw[C-2])%=mod;

        (ans[x] += s) %= mod;
    }

    // propagation to children
    ll nd0 = dp0, nd1 = dp1;
    for(int nx:G[x])if(nx!=p)
    {
        // children
        (nd0 += dp[nx][0]) %= mod;
        (nd1 += dp[nx][1]) %= mod;
    }
    C--; // 行き先のぶん

    // cond.1
    if(C>0)
    {
        (nd0 += pw[C]-2+mod) %= mod;
        (nd1 += pw[C]-2+mod) %= mod;
    }

    ll SUM = dp1;
    if(C>1)
    {
        ll s = dp1;
        ll d = (dp1*dp1)%mod;

        // cond.2
        (nd0 += dp1*(pw[C-1]-1)) %= mod;
        (nd1 += dp1*(pw[C-1]-1)) %= mod;
        for(int nx:G[x])if(nx!=p)
        {
            // cond.2
            (nd0 += dp[nx][1]*(pw[C-1]-1)) %= mod;
            (nd1 += dp[nx][1]*(pw[C-1]-1)) %= mod;

            (s += dp[nx][1]) %= mod;
            (d += dp[nx][1]*dp[nx][1]) %= mod;
            (SUM += dp[nx][1]) %= mod;
        }

        // cond.3
        s = (s*s-d+mod)%mod;
        (s *= MOD_INV) %= mod;
        (s *= pw[C-2])%=mod;

        (nd0 += s) %= mod;
    }

    // 子ノードにdfsを伸ばしていくが、その際に足してしまっている余計なものを引いた値を伝播
    for(int nx:G[x])if(nx!=p)
    {
        ll t0 = nd0, t1 = nd1;
        t0 = (t0 - dp[nx][0] + mod)%mod;
        t1 = (t1 - dp[nx][1] + mod)%mod;
        if(C>1)
        {
            t0 = (t0 - (dp[nx][1]*(pw[C-1]-1))%mod + mod)%mod;
            t1 = (t1 - (dp[nx][1]*(pw[C-1]-1))%mod + mod)%mod;

            ll dim = (dp[nx][1]*(SUM-dp[nx][1]))%mod;
            (dim *= pw[C-2])%=mod;
            t0 = (t0 - dim + mod)%mod;
        }
        dfs2(nx, x, t0, t1);
    }

    ans[x] %= mod;
}

void solve()
{
    int n;
    scanf(" %d", &n);

    G = vector<vector<int>>(n);
    ans = vector<ll>(n,0);
    dp = vector<vector<ll>>(n,vector<ll>(2,0));

    rep(i,n-1)
    {
        int u,v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);
    dfs2(0,-1,0,0);
    rep(i,n) printf("%lld\n", ans[i]);
}

int main()
{
    pw[0] = 1;
    for(int i=1; i<N; ++i) pw[i] = (pw[i-1]*2)%mod;

    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
