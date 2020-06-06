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

using pi = pair<int, int>;

const int A = 210;
const int N = 500;
const int INF = 19191919;

const int dx[6] = {1, 0, -1, 1, -1, 0};
const int dy[6] = {1, 1, 1, 0, 0, -1};

bool obj[N][N] = {};
int dp[N][N];

bool IN(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

int main() {
    int n, X, Y;
    cin >> n >> X >> Y;

    X += A;
    Y += A;

    rep(i, n) {
        int x, y;
        cin >> x >> y;
        obj[y + A][x + A] = true;
    }

    rep(i, N) rep(j, N) dp[i][j] = INF;
    dp[A][A] = 0;
    queue<pi> que({{A, A}});
    while (!que.empty()) {
        pi p = que.front();
        que.pop();

        int v = dp[p.fi][p.se];
        rep(d, 6) {
            int ny = p.fi + dy[d], nx = p.se + dx[d];
            if (IN(ny, nx) && !obj[ny][nx] && dp[ny][nx] > v + 1) {
                dp[ny][nx] = v + 1;
                que.push({ny, nx});
            }
        }
    }

    int ans = dp[Y][X];
    if (ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
