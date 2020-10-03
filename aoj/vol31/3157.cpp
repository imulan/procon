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

int main() {
    int n, K, T;
    cin >> n >> K >> T;
    vector<int> t(n), p(n);
    rep(i, n) cin >> t[i] >> p[i];

    vector<ll> x(T + 1);
    rep(i, n) {
        for (int j = T; j >= 0; --j) {
            int nj = j + t[i];
            if (nj > T) continue;
            x[nj] = max(x[nj], x[j] + p[i]);
        }
    }
    rep(i, T) x[i + 1] = max(x[i + 1], x[i]);

    vector<ll> dp(x);
    rep(i, T) {
        rep(j, T + 1) {
            int ni = i + K + j;
            if (ni > T) break;
            dp[ni] = max(dp[ni], dp[i] + x[j]);
        }
    }
    ll ans = 0;
    for (ll i : dp) ans = max(ans, i);
    cout << ans << "\n";
    return 0;
}
