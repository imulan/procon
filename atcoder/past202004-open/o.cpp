// clang-format off
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
// clang-format on

struct UF {
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N) : n(N), d(N, -1) {}
    int root(int v) {
        if (d[v] < 0) return v;
        return d[v] = root(d[v]);
    }
    bool unite(int X, int Y) {
        X = root(X);
        Y = root(Y);
        if (X == Y) return false;
        if (size(X) < size(Y)) swap(X, Y);
        d[X] += d[Y];
        d[Y] = X;
        return true;
    }
    int size(int v) { return -d[root(v)]; }
    bool same(int X, int Y) { return root(X) == root(Y); }
};

using pi = pair<int, int>;
using E = pair<ll, pi>;

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
void lca_dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    rep(i, G[v].size()) {
        if (G[v][i] != p) {  //親でなければ子
            lca_dfs(G[v][i], v, d + 1);
        }
    }
}

//初期化
void lca_init(int V) {
    // parent[0]とdepthの初期化
    lca_dfs(root, -1, 0);
    // parentの初期化
    for (int k = 0; k + 1 < MAX_LOG_V; ++k) {
        for (int v = 0; v < V; ++v) {
            if (parent[k][v] < 0)
                parent[k + 1][v] = -1;
            else
                parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

// uとvのLCAを求める
int lca(int u, int v) {
    // uとvの深さが同じになるまで親を辿る
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; ++k) {
        if ((depth[v] - depth[u]) >> k & 1) v = parent[k][v];
    }
    if (u == v) return u;
    //二分探索でLCAを求める
    for (int k = MAX_LOG_V - 1; k >= 0; --k) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

ll dp[MAX_LOG_V][MAX_V];

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    vector<ll> c(m);
    vector<E> edge(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i];
        --b[i];

        edge[i] = {c[i], {a[i], b[i]}};
    }

    sort(all(edge));

    map<pi, ll> mst;
    ll mst_cost = 0;

    UF uf(n);
    for (const auto& e : edge) {
        int u = e.se.fi, v = e.se.se;
        if (uf.unite(u, v)) {
            mst[{u, v}] = mst[{v, u}] = e.fi;
            mst_cost += e.fi;

            G[u].pb(v);
            G[v].pb(u);
        }
    }

    lca_init(n);

    rep(i, n) {
        int par = parent[0][i];
        if (par != -1) dp[0][i] = mst[{i, par}];
    }

    for (int i = 1; i < MAX_LOG_V; ++i) {
        rep(j, n) {
            int p = parent[i - 1][j];
            if (p == -1) p = 0;
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][p]);
        }
    }

    auto find_mx = [&](int u, int v) {
        ll ret = 0;

        int L = lca(u, v);
        int dL = depth[L];
        for (int x : {u, v}) {
            int now = depth[x];
            for (int i = MAX_LOG_V - 1; i >= 0; --i) {
                int d = 1 << i;
                if (now - d >= dL) {
                    ret = max(ret, dp[i][x]);
                    x = parent[i][x];
                    now -= d;
                }
            }
        }
        return ret;
    };

    rep(i, m) {
        pi e = {a[i], b[i]};
        ll ans = mst_cost;
        if (!mst.count(e)) ans += c[i] - find_mx(a[i], b[i]);
        cout << ans << "\n";
    }
    return 0;
}
