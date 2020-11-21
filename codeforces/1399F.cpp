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

int solve() {
    int n;
    scanf(" %d", &n);

    vector<pi> v(n);
    rep(i, n) {
        int l, r;
        scanf(" %d %d", &l, &r);
        v[i] = {l, r};
    }
    v.pb({0, 19191919});  // dummy
    ++n;
    sort(all(v));

    vector<int> nx(n);
    rep(i, n) {
        int t = i;
        while (t < n && v[i].se >= v[t].fi) ++t;
        nx[i] = t;
    }

    vector<pi> a(n);
    rep(i, n) a[i] = {v[i].se - v[i].fi, i};
    sort(all(a));

    vector<int> cov(n);
    rep(ai, n) {
        int idx = a[ai].se;
        int l = v[idx].fi, r = v[idx].se;

        vector<int> dp(n + 1);
        rep(i, n) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            if (l <= v[i].fi && v[i].se <= r) {
                int j = nx[i];
                dp[j] = max(dp[j], dp[i] + cov[i]);
            }
        }
        cov[idx] = dp[n] + 1;
    }

    return cov[0] - 1;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%d\n", solve());
    return 0;
}
