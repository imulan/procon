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

const int N = 50;
const int F = 10;
const int INF = 19191919;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int dp[N][N][F];

struct State {
    int y, x, f;
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    auto IN = [&](int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; };

    rep(i, N) rep(j, N) rep(k, F) dp[i][j][k] = INF;

    queue<State> que;
    State start, goal;
    rep(i, h) rep(j, w) {
        if (s[i][j] == 'S') {
            start = {i, j, 0};
            dp[i][j][0] = 0;
            que.push(start);
        }
        if (s[i][j] == 'G') goal = {i, j, 9};
    }

    while (!que.empty()) {
        State a = que.front();
        que.pop();

        int v = dp[a.y][a.x][a.f];
        rep(d, 4) {
            int ny = a.y + dy[d], nx = a.x + dx[d];
            if (!IN(ny, nx)) continue;

            int nf = a.f;
            if (nf < 9 && s[ny][nx] - '0' == nf + 1) ++nf;

            if (dp[ny][nx][nf] > v + 1) {
                dp[ny][nx][nf] = v + 1;
                que.push({ny, nx, nf});
            }
        }
    }

    int ans = dp[goal.y][goal.x][goal.f];
    if (ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
