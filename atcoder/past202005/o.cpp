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

/* MinCostFlow */

using pi = pair<ll, int>;

// (行き先, 容量, コスト, 逆辺)
struct edge {
    int to;
    ll cap;
    ll cost;
    int rev;
};

int V;                         // TODO:initialize
const int MAX_V = 555;         // TODO:initialize
const ll INF = LLONG_MAX / 3;  // TODO:initialize
vector<edge> G[MAX_V];
ll h[MAX_V];  // ポテンシャル
ll dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];  // 直前の頂点と辺

void add_edge(int from, int to, ll cap, ll cost) {
    G[from].pb({to, cap, cost, (int)G[to].size()});
    G[to].pb({from, 0, -cost, (int)G[from].size() - 1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
ll min_cost_flow(int s, int t, int f, bool neg = false) {
    ll res = 0;
    fill(h, h + V, 0);
    while (f > 0) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        fill(dist, dist + V, INF);
        dist[s] = 0;
        if (neg) {
            // bellman-fordでhを更新
            neg = false;
            bool update;
            do {
                update = false;
                rep(v, V) {
                    if (dist[v] == INF) continue;
                    rep(i, G[v].size()) {
                        edge &e = G[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            } while (update);
        } else {
            // dijkstraでhを更新
            pq.push(pi(0, s));
            while (!pq.empty()) {
                pi p = pq.top();
                pq.pop();
                int v = p.se;
                if (p.fi > dist[v]) continue;
                rep(i, G[v].size()) {
                    edge &e = G[v][i];
                    if (e.cap > 0 &&
                        dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.push(pi(dist[e.to], e.to));
                    }
                }
            }
        }

        // これ以上流せない
        if (dist[t] == INF) return -1;
        rep(v, V) h[v] += dist[v];

        // s-t間の最短路に沿って目一杯流す
        ll d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];

        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

const ll M = 100006;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n), r(3);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, 3) cin >> r[i];

    vector<vector<ll>> s(3, vector<ll>(n)), t(n, vector<ll>(3));
    rep(i, 3) rep(j, n) {
        s[i][j] = a[j];
        rep(loop, i + 1)(s[i][j] *= b[j]) %= r[i];
    }
    rep(i, n) rep(j, 3) {
        t[i][j] = a[i];
        rep(loop, j + 1) t[i][j] *= b[i];

        rep(k, j) t[i][j] -= t[i][k];
    }

    V = n + 5;
    int S = n + 3, T = n + 4;
    int R[3];
    rep(i, 3) R[i] = n + i;

    rep(i, 3) {
        add_edge(S, R[i], m, 0);
        rep(j, n) add_edge(R[i], j, 1, M - s[i][j]);
    }
    rep(i, n) rep(j, 3) add_edge(i, T, 1, t[i][j]);

    cout << M * 3 * m - min_cost_flow(S, T, 3 * m) << "\n";
    return 0;
}
