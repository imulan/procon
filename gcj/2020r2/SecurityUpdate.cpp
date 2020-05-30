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

using pi = pair<int, int>;
const int INF = 10000;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> z(n);
    for (int i = 1; i < n; ++i) cin >> z[i];

    vector<vector<int>> G(n);
    map<pi, int> e2id;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
        e2id[{u, v}] = e2id[{v, u}] = i;
    }

    vector<int> lat;
    priority_queue<pi, vector<pi>, greater<pi>> num_pq;
    rep(i, n) {
        if (z[i] >= 0)
            lat.pb(z[i]);
        else
            num_pq.push({-z[i], i});
    }

    vector<int> x(z);
    while (!num_pq.empty()) {
        sort(all(lat));

        pi p = num_pq.top();
        num_pq.pop();

        int li = p.fi - 1, idx = p.se;

        x[idx] = lat[li] + 1;
        lat.pb(x[idx]);
    }

    vector<int> y(m, INF);
    queue<int> que({0});
    vector<bool> vis(n);
    vis[0] = true;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int e : G[v])
            if (!vis[e]) {
                if (x[v] < x[e]) {
                    que.push(e);
                    vis[e] = true;
                    y[e2id[{v, e}]] = x[e] - x[v];
                }
            }
    }

    rep(i, m) printf("%d%c", y[i], " \n"[i == m - 1]);
}

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        printf("Case #%d: ", i + 1);
        // solve_easy();
        solve();
    }
    return 0;
}
