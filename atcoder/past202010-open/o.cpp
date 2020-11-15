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
using R = pair<pi, ll>;

const ll INF = LLONG_MAX / 3;

struct MaxSegTree {
    int n;
    vector<ll> dat;
    // 初期化
    MaxSegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<ll>(2 * n - 1, -INF);
    }

    void update(int k, ll a) {
        k += n - 1;
        dat[k] = max(dat[k], a);
        //更新
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return -INF;

        if (a <= l && r <= b) return dat[k];

        ll vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
    // [a,b)
    ll query(int a, int b) { return _query(a, b, 0, 0, n); }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> s = a;
    rep(i, n - 1) s[i + 1] += s[i];
    auto get_s = [&](int idx) {
        if (idx < 0) return 0LL;
        return s[idx];
    };

    vector<R> v(m);
    rep(i, m) {
        int l, r, c;
        cin >> l >> r >> c;
        --l;
        --r;
        v[i] = {{l, r}, c};
    }
    sort(all(v));

    MaxSegTree st(n + 1), st_s(n + 1);
    vector<ll> dp(n + 1);
    auto UPD = [&](int idx) {
        st.update(idx, dp[idx]);
        st_s.update(idx, dp[idx] - get_s(idx - 1));
    };
    rep(i, n + 1) UPD(i);

    rep(i, m) {
        int l = v[i].fi.fi, r = v[i].fi.se;
        ll c = v[i].se;

        ll v0 = st.query(0, l + 1) + get_s(r) - get_s(l - 1) - c;
        ll v1 = st_s.query(l + 1, r) + get_s(r) - c;
        dp[r + 1] = max({dp[r + 1], v0, v1});
        UPD(r + 1);
    }

    ll ans = 0;
    for (auto i : dp) ans = max(ans, i);
    cout << ans << "\n";
    return 0;
}
