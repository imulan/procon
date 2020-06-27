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

const int INF = 19191919;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, k;
    cin >> h >> w >> k;

    pi start, goal;
    cin >> start.fi >> start.se;
    --start.fi;
    --start.se;
    cin >> goal.fi >> goal.se;
    --goal.fi;
    --goal.se;

    vector<string> c(h);
    rep(i, h) cin >> c[i];

    vector<set<int>> X(h), Y(w), bx(h), by(w);
    rep(i, h) rep(j, w) {
        if (c[i][j] == '@') {
            bx[i].insert(j);
            by[j].insert(i);
        } else {
            X[i].insert(j);
            Y[j].insert(i);
        }
    }
    rep(i, h) for (int j : {-1, 1}) {
        X[i].insert(j * INF);
        bx[i].insert(j * INF);
    }
    rep(i, w) for (int j : {-1, 1}) {
        Y[i].insert(j * INF);
        by[i].insert(j * INF);
    }

    queue<pi> que;
    auto PUSH = [&](pi p) {
        que.push(p);
        int y = p.fi, x = p.se;
        X[y].erase(x);
        Y[x].erase(y);
    };

    vector<vector<int>> dp(h, vector<int>(w, INF));
    dp[start.fi][start.se] = 0;
    PUSH(start);
    while (!que.empty()) {
        pi now = que.front();
        que.pop();

        int y = now.fi, x = now.se, D = dp[y][x];

        int block;
        vector<int> nxt;

        // right
        auto b_itr = bx[y].lower_bound(x);
        block = *b_itr;
        auto itr = X[y].lower_bound(x);
        while (1) {
            int nx = *itr;
            if (abs(x - nx) > k) break;
            if (block < nx) break;

            if (dp[y][nx] > D + 1) {
                dp[y][nx] = D + 1;
                nxt.pb(nx);
            }
            ++itr;
        }
        for (int i : nxt) PUSH({y, i});
        nxt.clear();

        // left
        --b_itr;
        block = *b_itr;
        itr = X[y].lower_bound(x);
        --itr;
        while (1) {
            int nx = *itr;
            if (abs(x - nx) > k) break;
            if (nx < block) break;

            if (dp[y][nx] > D + 1) {
                dp[y][nx] = D + 1;
                nxt.pb(nx);
            }
            --itr;
        }
        for (int i : nxt) PUSH({y, i});
        nxt.clear();

        // down
        b_itr = by[x].lower_bound(y);
        block = *b_itr;
        itr = Y[x].lower_bound(y);
        while (1) {
            int ny = *itr;
            if (abs(y - ny) > k) break;
            if (block < ny) break;

            if (dp[ny][x] > D + 1) {
                dp[ny][x] = D + 1;
                nxt.pb(ny);
            }
            ++itr;
        }
        for (int i : nxt) PUSH({i, x});
        nxt.clear();

        // up
        --b_itr;
        block = *b_itr;
        itr = Y[x].lower_bound(y);
        --itr;
        while (1) {
            int ny = *itr;
            if (abs(y - ny) > k) break;
            if (ny < block) break;

            if (dp[ny][x] > D + 1) {
                dp[ny][x] = D + 1;
                nxt.pb(ny);
            }
            --itr;
        }
        for (int i : nxt) PUSH({i, x});
        nxt.clear();
    }

    int ans = dp[goal.fi][goal.se];
    if (ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
