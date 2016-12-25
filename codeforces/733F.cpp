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
// (w,c),(a,b);
typedef pair<pi,pi> edge;

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

//ノードの個数
const int MAX_V = 200000;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 19;
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

map<edge,int> eid_for_answer;
map<pi,int> edge_to_id;
int max_cost_edge_idx[MAX_LOG_V][MAX_V];

edge e[200000];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m) scanf(" %d", &e[i].fi.fi);
    rep(i,m) scanf(" %d", &e[i].fi.se);

    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        e[i].se.fi = a;
        e[i].se.se = b;

        eid_for_answer[e[i]] = i;
        eid_for_answer[e[i]] = i;
    }

    int S;
    scanf(" %d", &S);

    sort(e,e+m);
    UF uf(n);

    ll mst_cost=0;
    vector<bool> used(m,false);
    rep(i,m)
    {
        int a=e[i].se.fi, b=e[i].se.se;
        if(!uf.same(a,b))
        {
            uf.unite(a,b);

            mst_cost += e[i].fi.fi;
            used[i] = true;

            G[a].pb(b);
            G[b].pb(a);

            edge_to_id[pi(a,b)] = i;
            edge_to_id[pi(b,a)] = i;
        }
    }

    lca_init(n);

    // 木の上のpath上で最大のwを持つ辺のidをダブリングして持っておく
    max_cost_edge_idx[0][0]=-1;
    for(int i=1; i<n; ++i) max_cost_edge_idx[0][i]=edge_to_id[pi(i,parent[0][i])];

    rep(i,MAX_LOG_V-1)rep(j,n)
    {
        if(j==0) max_cost_edge_idx[i+1][j]=-1;
        else
        {
            if(parent[i][j]==0) max_cost_edge_idx[i+1][j] = max_cost_edge_idx[i][j];
            else
            {
                int a = max_cost_edge_idx[i][j];
                int b = max_cost_edge_idx[i][parent[i][j]];
                max_cost_edge_idx[i+1][j] = (e[a].fi.fi>e[b].fi.fi)?a:b;
            }
        }
    }

    ll ans = mst_cost;
    int add = -1, rem = -1;

    rep(i,m)
    {
        if(used[i])
        {
            int sub = S/e[i].fi.se;
            if(ans > mst_cost-sub)
            {
                ans = mst_cost-sub;
                add = i;
                rem = -1;
            }
        }
        else
        {
            int a = e[i].se.fi, b=e[i].se.se;
            int L = lca(a,b);
            int max_idx = -1;

            for(int j=MAX_LOG_V-1; j>=0; --j)
            {
                if(depth[a] - depth[L] >= 1<<j)
                {
                    int t = max_cost_edge_idx[j][a];
                    if(max_idx == -1 || e[t].fi.fi>e[max_idx].fi.fi) max_idx = t;
                    a = parent[j][a];
                }
                if(depth[b] - depth[L] >= 1<<j)
                {
                    int t = max_cost_edge_idx[j][b];
                    if(max_idx == -1 || e[t].fi.fi>e[max_idx].fi.fi) max_idx = t;
                    b = parent[j][b];
                }
            }

            if(ans > mst_cost - e[max_idx].fi.fi + e[i].fi.fi - S/e[i].fi.se)
            {
                ans = mst_cost - e[max_idx].fi.fi + e[i].fi.fi - S/e[i].fi.se;
                add = i;
                rem = max_idx;
            }
        }
    }

    printf("%lld\n", ans);
    rep(i,m)
    {
        if(i==add || (used[i]&&rem!=i))
        {
            printf("%d ", eid_for_answer[e[i]]+1);
            if(i==add) printf("%d\n", e[i].fi.fi - S/e[i].fi.se);
            else printf("%d\n", e[i].fi.fi);
        }
    }
    return 0;
}
