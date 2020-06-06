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
const int INF = 19191919;

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    rep(i, m) {
        int u, v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    int s, k;
    scanf(" %d %d", &s, &k);
    --s;
    vector<int> t(k);
    rep(i, k) {
        scanf(" %d", &t[i]);
        --t[i];
    }

    auto BFS = [&](int from) {
        vector<int> d(n, INF);
        d[from] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, from});
        while (!pq.empty()) {
            pi p = pq.top();
            pq.pop();

            int v = p.se;
            if (p.fi > d[v]) continue;

            for (int e : G[v]) {
                if (d[e] > d[v] + 1) {
                    d[e] = d[v] + 1;
                    pq.push({d[e], e});
                }
            }
        }
        return d;
    };

    vector<vector<int>> d(k, vector<int>(k));
    rep(i, k) {
        vector<int> dt = BFS(t[i]);
        rep(j, k) d[i][j] = dt[t[j]];
    }

    vector<vector<int>> dp(1 << k, vector<int>(k, INF));
    vector<int> ds = BFS(s);
    rep(i, k) dp[1 << i][i] = ds[t[i]];

    rep(mask, 1 << k) rep(i, k) if (dp[mask][i] < INF) {
        rep(j, k) {
            if (mask >> j & 1) continue;
            int nmask = mask | (1 << j);
            dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + d[i][j]);
        }
    }

    int ans = INF;
    rep(i, k) ans = min(ans, dp[(1 << k) - 1][i]);
    printf("%d\n", ans);
    return 0;
}
