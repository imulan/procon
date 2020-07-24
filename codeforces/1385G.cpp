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

void solve() {
    int n;
    cin >> n;

    vector<int> ct(n);
    vector<vector<pi>> pos(n);
    rep(i, 2) rep(j, n) {
        int a;
        cin >> a;
        --a;

        ++ct[a];
        pos[a].pb({i, j});
    }

    rep(i, n) if (ct[i] != 2) {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> G(2 * n);
    auto CONNECT = [&](int u, int v) {
        G[u].pb(v);
        G[v].pb(u);
    };

    rep(i, n) {
        pi x = pos[i][0], y = pos[i][1];
        int u = x.se, v = y.se;
        if (x.fi == y.fi) {
            CONNECT(u, n + v);
            CONNECT(n + u, v);
        } else {
            CONNECT(u, v);
            CONNECT(n + u, n + v);
        }
    }

    vector<int> ans;
    vector<bool> vis(2 * n);
    rep(i, n) if (!vis[i]) {
        vis[i] = true;
        queue<int> que({i});
        vector<int> cc({i});
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int e : G[v])
                if (!vis[e]) {
                    vis[e] = true;
                    que.push(e);
                    cc.pb(e);
                }
        }

        vector<int> a, b;
        for (int x : cc) {
            if (x < n) {
                a.pb(x);
            } else {
                b.pb(x - n);
                vis[x - n] = true;
            }
        }
        if (a.size() < b.size()) swap(a, b);
        for (int x : b) ans.pb(x);
    }

    int k = ans.size();
    cout << k << "\n";
    rep(i, k) {
        if (i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
