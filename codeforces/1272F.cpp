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

struct State {
    int si, ti, b;
};

const int N = 202;
const int INF = 19191919;
int dp[N][N][N];
State par[N][N][N];

int main() {
    string s, t;
    cin >> s >> t;
    int S = s.size(), T = t.size();

    rep(i, N) rep(j, N) rep(k, N) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    queue<State> que;
    que.push({0, 0, 0});
    while (!que.empty()) {
        State now = que.front();
        que.pop();

        int v = dp[now.si][now.ti][now.b];
        for (char c : {'(', ')'}) {
            int add = 1;
            if (c == ')') add = -1;
            int nk = now.b + add;
            if (0 <= nk && nk < N) {
                int ni = now.si, nj = now.ti;
                if (ni < S && s[ni] == c) ++ni;
                if (nj < T && t[nj] == c) ++nj;
                if (dp[ni][nj][nk] > v + 1) {
                    dp[ni][nj][nk] = v + 1;
                    par[ni][nj][nk] = now;
                    que.push({ni, nj, nk});
                }
            }
        }
    }

    State x = {S, T, 0};
    string ans = "";
    while (1) {
        if (x.si == 0 && x.ti == 0 && x.b == 0) break;

        State nx = par[x.si][x.ti][x.b];
        if (nx.b > x.b)
            ans += ')';
        else
            ans += '(';
        x = nx;
    }
    reverse(all(ans));
    cout << ans << "\n";
    return 0;
}
