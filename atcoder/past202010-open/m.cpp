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

using pi = pair<int, int>;
pi col[MAX_LOG_V][MAX_V];
pi DEF = {0, -1};

void UPD(int d, int v, int c, int pri) {
    pi t = col[d][v];
    if (t.se < pri) col[d][v] = {c, pri};
}

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);
    vector<int> a(n - 1), b(n - 1);
    rep(i, n - 1) {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }
    lca_init(n);

    rep(i, MAX_LOG_V) rep(j, MAX_V) col[i][j] = DEF;

    rep(qi, q) {
        int u, v, c;
        scanf(" %d %d %d", &u, &v, &c);
        --u;
        --v;

        int L = lca(u, v);
        int now = u;
        for (int i = MAX_LOG_V - 1; i >= 0; --i) {
            if (depth[now] - (1 << i) >= depth[L]) {
                UPD(i, now, c, qi);
                now = parent[i][now];
            }
        }

        now = v;
        for (int i = MAX_LOG_V - 1; i >= 0; --i) {
            if (depth[now] - (1 << i) >= depth[L]) {
                UPD(i, now, c, qi);
                now = parent[i][now];
            }
        }
    }

    for (int i = MAX_LOG_V - 1; i > 0; --i) rep(v, n) if (col[i][v] != DEF) {
            int c = col[i][v].fi, pri = col[i][v].se;

            int p = parent[i - 1][v];
            UPD(i - 1, v, c, pri);
            UPD(i - 1, p, c, pri);
        }

    rep(i, n - 1) {
        int u = a[i], v = b[i];
        if (depth[u] > depth[v]) swap(u, v);
        printf("%d\n", col[0][v].fi);
    }
    return 0;
}
