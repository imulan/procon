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

ll solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a;
    --b;
    --c;

    vector<ll> p(m);
    rep(i, m) cin >> p[i];
    sort(all(p));

    vector<vector<int>> G(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    auto BFS = [&](int start) {
        vector<int> d(n, n);
        d[start] = 0;
        queue<int> que({start});
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int e : G[v])
                if (d[e] > d[v] + 1) {
                    d[e] = d[v] + 1;
                    que.push(e);
                }
        }
        return d;
    };

    vector<int> da = BFS(a), db = BFS(b), dc = BFS(c);

    vector<ll> pre(p);
    rep(i, m - 1) pre[i + 1] += pre[i];

    auto SUM = [&](int l, int r) {
        if (r < l) return 0LL;

        ll ret = pre[r];
        if (l > 0) ret -= pre[l - 1];
        return ret;
    };

    ll ans = LLONG_MAX;
    rep(i, n) {
        int B = db[i];
        ll t = 2 * SUM(0, B - 1);

        int X = da[i] + dc[i];
        if (B + X > m) continue;
        // printf(" %d :: %d + %d  m %d\n", i, B, X, m);

        t += SUM(B, B + X - 1);
        ans = min(ans, t);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
