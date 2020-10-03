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

struct SCC {
    int V;
    vector<vector<int>> G, rG;
    vector<int> vs;   // 帰りがけ順の並び
    vector<int> cmp;  //属する強連結成分トポロジカル順序
    vector<bool> used;

    SCC() {}
    SCC(int n) {
        V = n;
        G = vector<vector<int>>(n);
        rG = vector<vector<int>>(n);
    }

    void add_edge(int from, int to) {
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v) {
        used[v] = true;
        rep(i, G[v].size()) if (!used[G[v][i]]) dfs(G[v][i]);
        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        rep(i, rG[v].size()) if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }

    int scc() {
        used = vector<bool>(V, false);
        vs.clear();
        rep(i, V) if (!used[i]) dfs(i);

        used = vector<bool>(V, false);
        cmp = vector<int>(V);
        int num_scc = 0;
        for (int i = vs.size() - 1; i >= 0; --i)
            if (!used[vs[i]]) rdfs(vs[i], num_scc++);
        return num_scc;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    SCC s(n);

    vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        s.add_edge(a[i], b[i]);
    }

    const int V = s.scc();
    vector<vector<int>> rG(V);
    rep(i, m) {
        int u = s.cmp[a[i]], v = s.cmp[b[i]];
        if (u != v) rG[v].pb(u);
    }

    vector<bool> vis(V);
    auto MOVE = [&](int x) {
        if (vis[x]) return;
        vis[x] = true;
        queue<int> que({x});
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int e : rG[v])
                if (!vis[e]) {
                    vis[e] = true;
                    que.push(e);
                }
        }
    };

    MOVE(s.cmp[0]);

    int q;
    cin >> q;
    rep(qi, q) {
        int x, y;
        cin >> x >> y;
        --y;
        if (x == 1)
            MOVE(s.cmp[y]);
        else
            cout << (vis[s.cmp[y]] ? "YES" : "NO") << "\n";
    }
    return 0;
}
