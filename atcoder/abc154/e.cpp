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

const int N = 111, K = 4;
ll dp[N][K][2];

int main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    dp[0][0][0] = 1;
    rep(i, n) rep(j, k + 1) rep(x, 2) {
        int v = s[i] - '0';

        int r = v;
        if (x == 1) r = 9;
        rep(y, r + 1) {
            int nj = j;
            if (y > 0) ++nj;
            if (nj > k) continue;

            int nx = x;
            if (y < r) nx = 1;
            dp[i + 1][nj][nx] += dp[i][j][x];
        }
    }

    ll ans = 0;
    rep(i, 2) ans += dp[n][k][i];
    cout << ans << "\n";
    return 0;
}
