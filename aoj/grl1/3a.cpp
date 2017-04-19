#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int V; // 頂点数 TODO:initialize
const int MAX_V = 100000; // 最大の頂点数 TODO:initialize

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

int main()
{
    int v,e;
    scanf(" %d %d", &v ,&e);
    while(e--)
    {
        int s,t;
        scanf(" %d %d", &s, &t);
        G[s].pb(t);
        G[t].pb(s);
    }

    V=v;
    detect_ap(0);

    rep(i,v)if(ap[i]) printf("%d\n", i);
    return 0;
}
