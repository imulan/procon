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

using State = tuple<int, int, int>;
using D = double;
using P = pair<D, State>;

const D INF = 1e7;
const D eps = 1e-7;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, k;
    cin >> h >> w >> k;

    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    --sy;
    --sx;
    --gy;
    --gx;

    vector<string> c(h);
    rep(i, h) cin >> c[i];

    auto OK = [&](int y, int x) {
        return 0 <= y && y < h && 0 <= x && x < w && c[y][x] == '.';
    };

    vector<vector<vector<D>>> dp(h, vector<vector<D>>(w, vector<D>(4, INF)));
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, 4) {
        dp[sy][sx][i] = 0;
        pq.push({0, {sy, sx, i}});
    }

    while (!pq.empty()) {
        P now = pq.top();
        pq.pop();

        State s = now.se;
        int y = get<0>(s), x = get<1>(s), d = get<2>(s);
        D val = dp[y][x][d];
        if (now.fi - eps > val) continue;

        int ny = y + dy[d], nx = x + dx[d];
        if (OK(ny, nx)) {
            D ndp = val + 1.0 / k;
            if (dp[ny][nx][d] - eps > ndp) {
                dp[ny][nx][d] = ndp;
                pq.push({ndp, {ny, nx, d}});
            }
        }

        rep(i, 4) {
            D ndp = ceil(val - eps);
            if (dp[y][x][i] - eps > ndp) {
                dp[y][x][i] = ndp;
                pq.push({ndp, {y, x, i}});
            }
        }
    }

    D mn = INF;
    rep(i, 4) mn = min(mn, dp[gy][gx][i]);

    int ans = (int)(ceil(mn - eps) + eps);
    if (abs(mn - INF) < eps) ans = -1;
    cout << ans << "\n";
    return 0;
}
