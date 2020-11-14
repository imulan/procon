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

const int INF = 1e9 + 7;

using pi = pair<int, int>;

struct edge {
    int to, cost;
};

int main() {
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> x(m), y(m), w(m);
    vector<vector<edge>> G(n);
    rep(i, m) {
        scanf(" %d %d %d", &x[i], &y[i], &w[i]);
        --x[i];
        --y[i];
        G[x[i]].pb({y[i], w[i]});
        G[y[i]].pb({x[i], w[i]});
    }

    vector<int> a(k), b(k);
    rep(i, k) {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
    }

    vector<vector<int>> d(n);
    rep(i, n) {
        vector<int> dp(n, INF);
        dp[i] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            pi p = pq.top();
            pq.pop();
            int v = p.se;
            if (dp[v] < p.fi) continue;
            for (const auto& e : G[v]) {
                if (dp[e.to] > dp[v] + e.cost) {
                    dp[e.to] = dp[v] + e.cost;
                    pq.push({dp[e.to], e.to});
                }
            }
        }
        d[i] = dp;
    }

    int ans = INF;
    rep(i, m) {
        int t = 0;
        rep(j, k) {
            int add = d[a[j]][b[j]];
            add = min(add, d[a[j]][x[i]] + d[y[i]][b[j]]);
            add = min(add, d[a[j]][y[i]] + d[x[i]][b[j]]);
            t += add;
        }
        ans = min(ans, t);
    }
    printf("%d\n", ans);
    return 0;
}
