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

const ll INF = 1000000000000LL;

ll solve() {
    int n, m, k, s;
    scanf(" %d %d %d %d", &n, &m, &k, &s);

    auto READ = [&](int sz) {
        vector<ll> v(sz);
        rep(i, k) scanf(" %lld", &v[i]);

        ll a, b, c, d;
        scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
        for (int i = k; i < sz; ++i)
            v[i] = (a * v[i - 2] + b * v[i - 1] + c) % d + 1;
        return v;
    };

    vector<ll> p = READ(n), q = READ(m);

    sort(all(p));
    sort(all(q));

    auto check = [&](ll t) {
        int idx = 0;
        rep(i, n) {
            ll dist = max(0LL, p[i] - q[idx]);
            if (t < dist) return false;

            // 先に左に行く
            ll rem = max(t - 2 * dist, 0LL);
            int nx = upper_bound(all(q), p[i] + rem) - q.begin();
            idx = max(idx, nx);

            // 先に右に行く
            rem = (t - dist) / 2;
            nx = upper_bound(all(q), p[i] + rem) - q.begin();
            idx = max(idx, nx);
            if (idx == m) return true;
        }
        return false;
    };

    ll ng = 0, ok = INF;
    while (ok - ng > 1) {
        ll mid = (ng + ok) / 2;

        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    int t;
    scanf(" %d", &t);
    rep(i, t) printf("Case #%d: %lld\n", i + 1, solve());
    return 0;
}
