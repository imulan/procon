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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

using pi = pair<int, int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    auto IN = [&](int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; };

    auto find_start = [&]() {
        rep(i, h) rep(j, w) if (s[i][j] == '.') return pi(i, j);
    };

    auto check = [&]() {
        vector<vector<bool>> vis(h, vector<bool>(w));

        pi b = find_start();
        vis[b.fi][b.se] = true;
        queue<pi> que({b});
        while (!que.empty()) {
            pi p = que.front();
            que.pop();
            rep(d, 4) {
                int y = p.fi + dy[d], x = p.se + dx[d];
                if (IN(y, x) && s[y][x] == '.' && !vis[y][x]) {
                    vis[y][x] = true;
                    que.push({y, x});
                }
            }
        }

        rep(i, h) rep(j, w) {
            if (s[i][j] == '.' && !vis[i][j]) return 0;
        }
        return 1;
    };

    int ans = 0;
    rep(yy, h) rep(xx, w) {
        if (s[yy][xx] == '.') continue;
        s[yy][xx] = '.';
        ans += check();
        s[yy][xx] = '#';
    }
    cout << ans << "\n";
    return 0;
}
