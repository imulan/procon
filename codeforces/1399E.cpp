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

// switch E1/E2
bool HARD = true;

vector<vector<int>> G;
vector<int> sz;
void dfs(int v, int p) {
    sz[v] = 0;
    bool leaf = true;
    for (int e : G[v])
        if (e != p) {
            leaf = false;
            dfs(e, v);
            sz[v] += sz[e];
        }

    if (leaf) sz[v] = 1;
}

int solve() {
    int n;
    ll S;
    cin >> n >> S;

    G = vector<vector<int>>(n);
    sz = vector<int>(n);

    vector<int> u(n - 1), v(n - 1), c(n - 1, 1);
    vector<ll> w(n - 1);
    rep(i, n - 1) {
        cin >> u[i] >> v[i] >> w[i];
        if (HARD) cin >> c[i];
        --u[i];
        --v[i];
        G[u[i]].pb(v[i]);
        G[v[i]].pb(u[i]);
    }
    dfs(0, -1);

    ll now = 0;
    vector<ll> x, y;
    rep(i, n - 1) {
        if (sz[u[i]] < sz[v[i]]) swap(u[i], v[i]);
        ll M = sz[v[i]];

        ll pre = w[i] * M, tw = w[i];
        now += pre;

        while (tw > 0) {
            ll nx = (tw / 2) * M;
            if (c[i] == 1)
                x.pb(pre - nx);
            else
                y.pb(pre - nx);

            pre = nx;
            tw /= 2;
        }
    }
    ll need = now - S;
    if (need <= 0) return 0;

    sort(all(x), greater<ll>());
    sort(all(y), greater<ll>());

    int X = x.size(), Y = y.size();
    vector<ll> px(X + 1), py(Y + 1);
    rep(i, X) px[i + 1] = px[i] + x[i];
    rep(i, Y) py[i + 1] = py[i] + y[i];

    auto check = [&](int z) {
        rep(i, Y + 1) {
            int r = min(X, z - 2 * i);
            if (r < 0) break;
            if (need <= px[r] + py[i]) return true;
        }
        return false;
    };

    int ng = 0, ok = X + 2 * Y;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
