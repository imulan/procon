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

const int N = 100000;
vector<int> G[N];
int n,k;

int sz[N],dp[N],ed[N];
int dfs(int x, int p)
{
    int ret = 0;

    sz[x] = 1;
    for(int nx:G[x])if(nx!=p)
    {
        ret = max(ret,dfs(nx,x));
        sz[x] += sz[nx];
    }
    if(sz[x]==1) dp[x] = -1;

    int ct = 0;
    for(int nx:G[x])if(nx!=p)
    {
        dp[x] = max(dp[x],dp[nx]);
        ed[x] = max(ed[x],ed[nx]);
        ct += (sz[nx]>=k);
    }
    ed[x] = max(ed[x],ct);

    int g0=-1, g1=-1;
    for(int nx:G[x])if(nx!=p)
    {
        int tmp = ct - (sz[nx]>=k);
        dp[x] = max(dp[x],ed[nx]+tmp);
        ed[x] = max(ed[x],ed[nx]+tmp);

        int tg = ed[nx]-(sz[nx]>=k);
        if(g1<tg) g1=tg;
        if(g0<g1) swap(g0,g1);
    }
    dp[x] = max(dp[x],ct+g0+g1);

    ret = max(ret,dp[x]+(n-sz[x]>=k));
    return ret;
}

int main()
{
    scanf(" %d %d", &n, &k);
    rep(i,n-1)
    {
        int u,v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    printf("%d\n", dfs(0,-1));
    return 0;
}
