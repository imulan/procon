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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    const int L = w / 2;

    vector<vector<int>> mx(h);
    rep(hi, h) {
        vector<vector<int>> x(L + 1, vector<int>(k, -INF));
        x[0][0] = 0;
        for (int v : a[hi]) {
            vector<vector<int>> nx(L + 1, vector<int>(k, -INF));

            rep(i, L + 1) rep(j, k) {
                if (i + 1 <= L)
                    nx[i + 1][(j + v) % k] =
                        max(nx[i + 1][(j + v) % k], x[i][j] + v);
                nx[i][j] = max(nx[i][j], x[i][j]);
            }
            swap(x, nx);
        }

        vector<int> y(k, -INF);
        rep(i, L + 1) rep(j, k) y[j] = max(y[j], x[i][j]);
        mx[hi] = y;
    }

    vector<int> dp(k, -INF);
    dp[0] = 0;
    rep(hi, h) {
        vector<int> nx(k, -INF);
        rep(i, k) {
            rep(j, k) {
                int idx = (i + j) % k;
                nx[idx] = max(nx[idx], dp[i] + mx[hi][j]);
            }
        }
        swap(dp, nx);
    }
    cout << dp[0] << "\n";
    return 0;
}
