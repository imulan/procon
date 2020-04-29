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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    const int L = 2 + n % 2;
    vector<vector<ll>> dp(n, vector<ll>(L, -INF));
    rep(i, L) dp[i][L - 1 - i] = a[i];
    rep(i, n - 1) rep(j, L) {
        if (dp[i][j] == -INF) continue;
        if (i + 2 < n) dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i + 2]);
        if (j > 0) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
    }
    cout << dp[n - 1][0] << "\n";
    return 0;
}
