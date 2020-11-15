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

const int H = 18;
const int W = 6;
const int N = 1 << W;

bool is_fit(int bit, string s) {
    rep(i, W) if (s[i] != '?') {
        int v = s[i] - '0', b = (bit >> i) & 1;
        if (v != b) return false;
    }
    return true;
}

// check y-row
int memo[N][N][N];
int check(int z, int y, int x) {
    if (memo[z][y][x] >= 0) return memo[z][y][x];

    vector<vector<int>> mat;
    for (int i : {x, y, z}) {
        vector<int> t(W);
        rep(j, W) t[j] = (i >> j) & 1;
        mat.pb(t);
    }

    rep(i, W) {
        int ct[2] = {};
        rep(j, 3)++ ct[mat[j][i]];

        for (int j : {-1, 1}) {
            int idx = i + j;
            if (0 <= idx && idx < W)
                ++ct[mat[1][idx]];
            else
                ++ct[0];
        }

        int f = mat[1][i];
        if (ct[f] < ct[!f]) return memo[z][y][x] = 0;
    }
    return memo[z][y][x] = 1;
}

int main() {
    vector<string> s(H);
    rep(i, H) cin >> s[i];

    vector<vector<ll>> dp(N, vector<ll>(N));
    rep(i, N) if (is_fit(i, s[0])) dp[i][0] = 1;

    memset(memo, -1, sizeof(memo));
    for (int hi = 1; hi < H; ++hi) {
        vector<vector<ll>> nx(N, vector<ll>(N));
        rep(k, N) if (is_fit(k, s[hi])) {
            rep(i, N) rep(j, N) if (check(k, i, j)) nx[k][i] += dp[i][j];
        }
        swap(dp, nx);
    }

    ll ans = 0;
    rep(i, N) rep(j, N) if (check(0, i, j)) ans += dp[i][j];
    cout << ans << "\n";
    return 0;
}
