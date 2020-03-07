#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

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

const ll INF = LLONG_MAX/3;

using pi = pair<int,int>;
using edge = pair<ll,pi>;
using P = pair<ll,int>;

//ノードの個数
const int MAX_V = 100010;
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

int main(){
    int n,m,k,q;
    scanf(" %d %d %d %d", &n, &m, &k, &q);

    vector<vector<pi>> wG(n);
    vector<edge> e(m);
    rep(i,m){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        e[i] = {w,{u,v}};
        wG[u].pb({v,w});
        wG[v].pb({u,w});
    }

    // Dijkstra
    vector<ll> d(n,INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i,k){
        d[i] = 0;
        pq.push({0,i});
    }
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi > d[v]) continue;
        for(const auto &x:wG[v]){
            int to = x.fi, cost = x.se;
            if(d[to] > d[v]+cost){
                d[to] = d[v]+cost;
                pq.push({d[to],to});
            }
        }
    }

    // update cost
    rep(i,m){
        int u = e[i].se.fi, v = e[i].se.se;
        ll w = e[i].fi;
        e[i].fi = w+d[u]+d[v];
    }
    sort(all(e));

    // MST
    UF uf(n);
    map<pi,ll> e2w;
    rep(i,m){
        int u = e[i].se.fi, v = e[i].se.se;
        if(uf.unite(u,v)){
            G[u].pb(v);
            G[v].pb(u);
            e2w[{u,v}] = e2w[{v,u}] = e[i].fi;
        }
    }

    lca_init(n);

    vector<vector<ll>> dp(MAX_LOG_V, vector<ll>(n,-1));
    for(int i=1; i<n; ++i){
        int p = parent[0][i];
        ll cost = e2w[{i,p}];
        dp[0][i] = cost;
    }

    for(int i=1; i<MAX_LOG_V; ++i){
        rep(j,n){
            dp[i][j] = dp[i-1][j];
            int p = parent[i-1][j];
            if(p>=0) dp[i][j] = max(dp[i-1][j], dp[i-1][p]);
        }
    }

    auto QUERY = [&](int c, int p){
        ll ret = -1;
        int now = c;
        for(int i=MAX_LOG_V-1; i>=0; --i){
            int par = parent[i][now];
            if(parent[i][now] < 0) continue;

            if(depth[par] < depth[p]) continue;
            ret = max(ret, dp[i][now]);

            now = par;
        }
        return ret;
    };

    rep(i,q){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        int L = lca(a,b);
        printf("%lld\n", max(QUERY(a,L), QUERY(b,L)));
    }
    return 0;
}
