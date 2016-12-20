#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

//ノードの個数
const int MAX_V = 100000;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 17;
//木の隣接リスト表現
vector<int> G[MAX_V];
//根のノード番号
int root = 0;

//親を2^k回辿って到達するノード(根を通り過ぎる場合,-1)
int parent[MAX_LOG_V][MAX_V];
//根からの深さ
int depth[MAX_V];

//現在vに注目、親はp、深さd
void lca_dfs(int v, int p, int d){
    parent[0][v]=p;
    depth[v]=d;
    rep(i,G[v].size()){
        if(G[v][i]!=p){ //親でなければ子
            lca_dfs(G[v][i], v, d+1);
        }
    }
}

//初期化
void lca_init(int V){
    //parent[0]とdepthの初期化
    lca_dfs(root, -1, 0);
    //parentの初期化
    for(int k=0; k+1<MAX_LOG_V; ++k){
        for(int v=0; v<V; ++v){
            if(parent[k][v] < 0) parent[k+1][v]=-1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

//uとvのLCAを求める
int lca(int u, int v){
    //uとvの深さが同じになるまで親を辿る
    if(depth[u] > depth[v]) swap(u,v);
    for(int k=0; k<MAX_LOG_V; ++k){
        if((depth[v]-depth[u])>>k & 1) v = parent[k][v];
    }
    if(u==v) return u;
    //二分探索でLCAを求める
    for(int k=MAX_LOG_V-1; k>=0; --k){
        if(parent[k][u] != parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

const int INF=12345678;
int d[MAX_V];

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> p(n);
    for(int i=1; i<n; ++i)
    {
        scanf(" %d", &p[i]);
        --p[i];

        G[p[i]].pb(i);
    }

    lca_init(n);

    vector<int> vis;
    fill(d,d+MAX_V,INF);
    d[0]=0;
    queue<int> que;
    que.push(0);
    vis.pb(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,G[v].size())
        {
            int nx=G[v][i];
            if(d[nx]>d[v]+1)
            {
                d[nx]=d[v]+1;
                que.push(nx);
                vis.pb(nx);
            }
        }
    }

    ll ans=0;
    rep(i,vis.size()-1)
    {
        // printf("%d %d\n", vis[i],vis[i+1]);
        ans += d[vis[i]]+d[vis[i+1]]-2*d[lca(vis[i],vis[i+1])];
    }
    printf("%lld\n", ans);
    return 0;
}
