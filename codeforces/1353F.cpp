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

const ll INF = LLONG_MAX / 3;

ll solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    auto FIX = [&](ll start) {
        if (a[0][0] < start) return INF;
        vector<vector<ll>> dp(n, vector<ll>(m, INF));
        dp[0][0] = a[0][0] - start;
        rep(i, n) rep(j, m) {
            ll h = start + i + j + 1;
            if (i + 1 < n && h <= a[i + 1][j]) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j] - h);
            }
            if (j + 1 < m && h <= a[i][j + 1]) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1] - h);
            }
        }
        return dp[n - 1][m - 1];
    };

    ll ans = INF;
    rep(i, n) rep(j, m) ans = min(ans, FIX(a[i][j] - i - j));
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
