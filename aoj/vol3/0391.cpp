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

struct edge{ int to,cost; };
vector<edge> wG[MAX_V];

int wd[MAX_V];

void calc_dist(int x, int par){
    for(const auto &e:wG[x])if(e.to != par){
        wd[e.to] = wd[x] + e.cost;
        calc_dist(e.to, x);
    }
}

int D(int u, int v){
    int l = lca(u,v);
    return depth[u]+depth[v]-2*depth[l];
}

int WD(int u, int v){
    int l = lca(u,v);
    return wd[u]+wd[v]-2*wd[l];
}

const int INF = 1e9+1;
// check u-v path
int f(int u, int v, int t){
    int LCA = lca(u,v);
    if(LCA == u) swap(u,v);

    auto g = [&](int x){
        int c = u,s = x;
        if(D(u,LCA) < x){
            c = v;
            s = D(u,v) - x;
        }

        for(int i=MAX_LOG_V-1; i>=0; --i)if(s>>i&1) c = parent[i][c];
        return max({WD(c,u), WD(c,v), WD(c,t)});
    };

    int l=0, r=D(u,v);
    while(r-l>2){
        int m1 = (l+r)/2;
        int m2 = m1+1;
        if(g(m1) >= g(m2)) l = m1;
        else r = m2;
    }

    int ret = INF;
    for(int i=l; i<=r; ++i) ret = min(ret, g(i));
    return ret;
}

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);
    rep(i,n-1){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;

        G[u].pb(v);
        G[v].pb(u);
        wG[u].pb({v,w});
        wG[v].pb({u,w});
    }

    lca_init(n);

    wd[root] = 0;
    calc_dist(root,-1);

    rep(i,q){
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        --c;

        int ans = min(f(a,b,c),f(a,c,b));
        printf("%d\n", ans);
    }
    return 0;
}
