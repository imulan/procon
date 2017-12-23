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

int ans = 0;
int sz[N];
int dp[N],ed[N];
void dfs(int x, int p)
{
    sz[x] = 1;
    for(int nx:G[x])if(nx!=p)
    {
        dfs(nx,x);
        sz[x] += sz[nx];
    }
    if(sz[x]==1) dp[x] = -1;

    int ct = 0;
    for(int nx:G[x])if(nx!=p)
    {
        ed[x] = max(ed[x],ed[nx]);
        dp[x] = max(dp[x],dp[nx]);
        ct += (sz[nx]>=k);
    }
    ed[x] = max(ed[x],ct);

    vector<int> gain;
    for(int nx:G[x])if(nx!=p)
    {
        int tmp = ct - (sz[nx]>=k);
        dp[x] = max(dp[x],ed[nx]+tmp);
        ed[x] = max(ed[x],ed[nx]+tmp);

        gain.pb(ed[nx]-(sz[nx]>=k));
    }

    sort(all(gain),greater<int>());
    if(gain.size()>=2) dp[x] = max(dp[x],ct+gain[0]+gain[1]);

    ans = max(ans,dp[x]+(n-sz[x]>=k));
    // printf(" %d: dp %d ed %d\n", x,dp[x],ed[x]);
}

int main()
{
    cin >>n >>k;
    rep(i,n-1)
    {
        int u,v;
        cin >>u >>v;
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);
    cout << ans << endl;
    return 0;
}
