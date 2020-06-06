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

const int INF = INT_MAX / 3;

int main() {
    int n, L;
    cin >> n >> L;

    vector<bool> h(L + 334);
    rep(i, n) {
        int x;
        cin >> x;
        h[x] = true;
    }

    int t[3];
    rep(i, 3) cin >> t[i];

    vector<int> dp(L + 334, INF);
    dp[0] = 0;
    rep(i, L) {
        // act 1
        int a = 0;
        if (h[i + 1]) a = t[2];
        dp[i + 1] = min(dp[i + 1], dp[i] + t[0] + a);

        // act 2
        a = 0;
        if (h[i + 2]) a = t[2];
        dp[i + 2] = min(dp[i + 2], dp[i] + t[0] + t[1] + a);

        if (i + 2 > L) dp[L] = min(dp[L], dp[i] + t[0] / 2 + t[1] / 2);

        // act 3
        a = 0;
        if (h[i + 4]) a = t[2];
        dp[i + 4] = min(dp[i + 4], dp[i] + t[0] + 3 * t[1] + a);

        if (i + 4 > L) {
            int x = t[0] / 2 + t[1] / 2 + t[1] * (L - 1 - i);
            dp[L] = min(dp[L], dp[i] + x);
        }
    }
    cout << dp[L] << "\n";
    return 0;
}
