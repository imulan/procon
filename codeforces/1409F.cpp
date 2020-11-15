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

const int INF = 19191919;

int main() {
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
    dp[0][0] = 0;
    for (char u : s) {
        vector<vector<int>> nx(n + 1, vector<int>(k + 1, -INF));
        rep(i, n + 1) rep(j, k + 1) if (dp[i][j] >= 0) {
            for (char c : {u, t[0], t[1]}) {
                int nj = j + (c != u);
                if (nj > k) continue;

                int ni = i + (c == t[0]);
                int add = i * (c == t[1]);
                nx[ni][nj] = max(nx[ni][nj], dp[i][j] + add);
            }
        }
        swap(dp, nx);
    }

    int ans = 0;
    rep(i, n + 1) rep(j, k + 1) ans = max(ans, dp[i][j]);
    cout << ans << "\n";
    return 0;
}
