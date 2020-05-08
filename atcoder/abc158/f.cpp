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

struct MaxSegTree {
    int n;
    vector<ll> dat;
    // 初期化
    MaxSegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<ll>(2 * n - 1, -1);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, ll a) {
        k += n - 1;
        dat[k] = a;
        //更新
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return -1;

        if (a <= l && r <= b) return dat[k];

        ll vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
    // [a,b)
    ll query(int a, int b) { return _query(a, b, 0, 0, n); }
};

const int mod = 998244353;

using pi = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<pi> robot(n);
    rep(i, n) {
        int x, d;
        cin >> x >> d;
        robot[i] = {x, d};
    }
    sort(all(robot));

    MaxSegTree st(n);
    vector<int> nx(n);
    rep(i, n) nx[i] = i + 1;

    for (int i = n - 1; i >= 0; --i) {
        int x = robot[i].fi + robot[i].se;
        int idx = lower_bound(all(robot), pi(x, 0)) - robot.begin();

        int r = st.query(i, idx);
        nx[i] = max(r, nx[i]);
        st.update(i, nx[i]);
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    rep(i, n) {
        (dp[i + 1] += dp[i]) %= mod;
        (dp[nx[i]] += dp[i]) %= mod;
    }
    cout << dp[n] << "\n";
    return 0;
}
