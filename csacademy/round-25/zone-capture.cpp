#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int V; // 頂点数 TODO:initialize
const int MAX_V = 1000001; // 最大の頂点数 TODO:initialize

vector<int> G[MAX_V]; // 隣接リスト表現
bool vis[MAX_V];
int timer, root;
int prenum[MAX_V]; // DFSの訪問順
int parent[MAX_V]; // DFSによって出来る木の親
int lowest[MAX_V]; // DFS木において頂点i以下にあるmin(prenum)

bool ap[MAX_V]; // 関節点かどうか

void dfs(int u, int prev)
{
    prenum[u] = timer;
    lowest[u] = timer;
    ++timer;

    vis[u] = true;
    int child = 0;

    rep(i,G[u].size())
    {
        int v = G[u][i];
        if(!vis[v])
        {
            parent[v] = u;
            ++child;
            dfs(v,u);
            lowest[u] = min(lowest[u],lowest[v]);
        }
        else if(u!=prev)
        {
            lowest[u] = min(lowest[u], prenum[v]);
        }
    }

    if(u==root)
    {
        if(child>=2) ap[u]=true;
    }
    else
    {
        if(prev!=root && prenum[prev]<=lowest[u]) ap[prev]=true;
    }
}

void detect_ap(int _root)
{
    memset(vis,0,sizeof(vis));
    memset(ap,0,sizeof(ap));

    root = _root;
    timer = 1;
    dfs(root,-1);
}

int f[1000][1000];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    int v_num=1;
    int black=0;
    rep(i,n)rep(j,m)
    {
        int v;
        scanf(" %d", &v);
        if(v==0) f[i][j] = v_num++;
        else
        {
            f[i][j]=-1;
            ++black;
        }
    }

    V = v_num;

    // グラフ構築
    #define IN(x,y) (0<=x && x<m && 0<=y && y<n)
    #define EDGE(x,y) (x==0 || x==m-1 || y==0 || y==n-1)
    int dx[2]={-1,0}, dy[2]={0,-1};
    rep(i,n)rep(j,m)
    {
        if(f[i][j]==-1) continue;

        if(EDGE(j,i))
        {
            G[0].pb(f[i][j]);
            G[f[i][j]].pb(0);
        }

        rep(d,2)
        {
            int nx=j+dx[d], ny=i+dy[d];
            if(IN(nx,ny) && f[ny][nx]!=-1)
            {
                G[f[i][j]].pb(f[ny][nx]);
                G[f[ny][nx]].pb(f[i][j]);
            }
        }
    }

    detect_ap(0);

    // rep(i,n)
    // {
    //     rep(j,m) printf("%2d", f[i][j]);
    //     printf("\n");
    // }
    // printf(" ---ap---\n");
    // rep(i,V)if(ap[i]) printf(" %d\n", i);
    // printf(" ------\n");

    // 関節点以外を塗りつぶす
    vector<int> group(V);
    vector<bool> vv(V,false), art;
    int g_num=0;
    rep(i,V)
    {
        if(vv[i]) continue;

        if(ap[i])
        {
            art.pb(true);
            group[i] = g_num;
            vv[i] = true;
        }
        else
        {
            art.pb(false);

            queue<int> que;
            que.push(i);
            group[i] = g_num;
            vv[i] = true;
            while(!que.empty())
            {
                int now = que.front();
                que.pop();
                rep(j,G[now].size())
                {
                    int nx=G[now][j];
                    if(!ap[nx] && !vv[nx])
                    {
                        que.push(nx);
                        group[nx] = g_num;
                        vv[nx] = true;
                    }
                }
            }
        }
        ++g_num;
    }

    // rep(i,V) printf(" group[%d] = %d\n", i,group[i]);

    // 新たにグラフ構築
    vector<vector<int>> g(g_num);
    rep(i,V)
    {
        if(ap[i])
        {
            set<int> e;
            rep(j,G[i].size())
            {
                int nx=G[i][j];
                e.insert(group[nx]);
            }

            for(const auto &x:e)
            {
                g[x].pb(group[i]);
                g[group[i]].pb(x);
            }
        }
    }

    vector<int> dist(g_num,123456789),par(g_num,-1);
    dist[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        rep(i,g[now].size())
        {
            int nx = g[now][i];
            if(dist[nx] > dist[now]+1)
            {
                par[nx] = now;
                que.push(nx);
                dist[nx] = dist[now]+1;
            }
        }
    }

    vector<pi> pp(g_num);
    rep(i,g_num) pp[i] = pi(-dist[i],i);
    sort(all(pp));

    vector<int> dp(g_num,0);
    rep(i,V) ++dp[group[i]];

    rep(i,g_num)
    {
        int now=pp[i].se;
        int P = par[now];

        if(P==-1) continue;
        // printf("  now = %d, P = %d\n", now,P);
        dp[P] += dp[now];
    }

    // rep(i,g_num) printf(" dp[%d] = %d\n", i,dp[i]);

    int max_v=1;
    rep(i,g_num)if(art[i]) max_v=max(max_v,dp[i]);

    printf("%d\n", black+max_v);
    return 0;
}
