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

const int L = 18;
const int N = 200002;
vector<int> G[N];
int p[L][N];
int d[N];

void dfs(int v, int par) {
    if (par != -1) d[v] = d[par] + 1;
    p[0][v] = par;
    for (int c : G[v])
        if (c != par) dfs(c, v);
}

int main() {
    int n, q;
    cin >> n >> q;
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0, -1);
    for (int i = 1; i < L; ++i) {
        rep(j, n) {
            if (p[i - 1][j] == -1)
                p[i][j] = -1;
            else
                p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }

    auto query = [&]() {
        int k;
        cin >> k;
        vector<pi> x(k);
        rep(i, k) {
            int v;
            cin >> v;
            --v;
            if (v != 0) v = p[0][v];

            x[i] = {d[v], v};
        }
        sort(all(x), greater<pi>());

        rep(i, k - 1) {
            int v = x[i].se, u = x[i + 1].se;

            int dv = d[v], du = d[u];
            for (int j = L - 1; j >= 0; --j) {
                int w = 1 << j;
                if (dv - w >= du) {
                    dv -= w;
                    v = p[j][v];
                }
            }

            if (v != u) return "NO";
        }

        return "YES";
    };

    while (q--) cout << query() << "\n";

    return 0;
}
