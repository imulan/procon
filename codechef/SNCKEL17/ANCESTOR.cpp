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

//ノードの個数
const int MAX_V = 500000;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 20;
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

using pi = pair<int,int>;

vector<int> g[MAX_V];
vector<int> E[MAX_V];

void DFS(int v, int p)
{
    rep(i,g[v].size())
    {
        int nx=g[v][i];
        if(nx==p) continue;

        if(lca(v,nx)==v) E[v].pb(nx);
        DFS(nx,v);
    }
}

int dp[MAX_V];
void DFS2(int v, int p)
{
    rep(i,E[v].size())
    {
        int nx=E[v][i];
        dp[nx] = max(dp[nx],dp[v]+1);
    }

    rep(i,G[v].size())
    {
        int nx=G[v][i];
        if(nx==p) continue;

        DFS2(nx,v);
    }
}

void solve()
{
    int n;
    scanf(" %d", &n);

    rep(i,n)
    {
        G[i].clear();
        g[i].clear();
        E[i].clear();
    }

    vector<pi> t1(n-1),t2(n-1);

    rep(i,n-1)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep(i,n-1)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }


    lca_init(n);
    DFS(0,-1);

    // rep(i,n)
    // {
    //     printf("i: %d:",i);
    //     for(const auto &ee:E[i]) printf(" %d", ee);
    //     printf("\n");
    // }

    fill(dp,dp+n,1);
    dp[0]=0;
    DFS2(0,-1);

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", dp[i]);
    }
    printf("\n");
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
