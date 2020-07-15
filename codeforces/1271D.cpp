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

const int N = 5005;

int main() {
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    vector<int> a(n), b(n), c(n);
    rep(i, n) scanf(" %d %d %d", &a[i], &b[i], &c[i]);

    vector<int> last(n);
    rep(i, n) last[i] = i;

    rep(i, m) {
        int u, v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        last[v] = max(last[v], u);
    }

    vector<vector<int>> p(n);
    rep(i, n) p[last[i]].pb(c[i]);

    vector<int> dp(N, -1);
    dp[k] = 0;
    rep(i, n) {
        sort(all(p[i]), greater<int>());
        int sz = p[i].size();
        vector<int> nx(N, -1);
        for (int j = a[i]; j < N; ++j)
            if (dp[j] >= 0) {
                int nj = j + b[i];
                int add = 0;
                rep(x, sz + 1) {
                    nx[nj - x] = max(nx[nj - x], dp[j] + add);
                    if (x < sz) add += p[i][x];
                }
            }
        swap(dp, nx);
    }

    int ans = -1;
    for (int i : dp) ans = max(ans, i);
    printf("%d\n", ans);
    return 0;
}
