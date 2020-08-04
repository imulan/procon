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

// for D2
const bool is_D2 = true;

const ll INF = LLONG_MAX / 5;

struct MinSegTree {
    int n;
    vector<ll> dat;
    // 初期化
    MinSegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<ll>(2 * n - 1, INF);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, ll a) {
        k += n - 1;
        dat[k] = a;
        //更新
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INF;

        if (a <= l && r <= b) return dat[k];

        ll vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
    // [a,b)
    ll query(int a, int b) { return _query(a, b, 0, 0, n); }
};

ll solve() {
    int n, m, a, b;
    scanf(" %d %d", &n, &m);
    if (is_D2)
        scanf(" %d %d", &a, &b);
    else {
        a = 1;
        b = n;
    }
    --a;
    --b;

    vector<int> p(n);
    vector<ll> c(n);
    rep(i, n) {
        if (is_D2)
            scanf(" %d", &p[i]);
        else
            p[i] = i;
        --p[i];

        scanf(" %lld", &c[i]);
        if (c[i] == 0) c[i] = INF;
    }
    c[a] = 0;
    c[b] = 0;

    vector<vector<int>> G(n);
    for (int i = 1; i < n; ++i) {
        int u = i, v = p[i];
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> par(n, -1);
    queue<int> que({b});
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int e : G[v])
            if (e != par[v]) {
                que.push(e);
                par[e] = v;
            }
    }

    vector<int> path;
    int now = a;
    while (now >= 0) {
        path.pb(now);
        now = par[now];
    }
    int P = path.size();

    vector<ll> dp(P, INF);
    MinSegTree st(P);

    auto UPD = [&](int idx, ll val) {
        dp[idx] = min(dp[idx], val);
        st.update(idx, dp[idx]);
    };
    UPD(0, 0);

    for (int i = 1; i < P; ++i) {
        UPD(i, st.query(max(0, i - m), i) + c[path[i]]);

        queue<pi> qq;
        for (int e : G[path[i]]) {
            if (e != par[path[i]] && e != path[i - 1]) qq.push({e, 1});
        }
        while (!qq.empty()) {
            pi pp = qq.front();
            qq.pop();
            int v = pp.fi, dep = pp.se;
            if (i - dep < 0) continue;

            UPD(i - dep, st.query(max(0, i - m + dep), i) + c[v]);

            for (int e : G[v])
                if (e != par[v]) qq.push({e, dep + 1});
        }
    }

    ll ans = dp[P - 1];
    if (ans == INF) ans = -1;
    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    rep(i, t) printf("Case #%d: %lld\n", i + 1, solve());
    return 0;
}
