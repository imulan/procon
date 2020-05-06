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

const int N = 200010;
const int INF = INT_MAX;

int a[N];
vector<int> G[N];

int ans[N];
int dp[N];
void dfs(int v, int p) {
    int idx = lower_bound(dp, dp + N, a[v]) - dp;
    int t = dp[idx];
    dp[idx] = a[v];
    ans[v] = lower_bound(dp, dp + N, INF) - dp - 1;

    for (int c : G[v])
        if (c != p) dfs(c, v);

    dp[idx] = t;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];

    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    fill(dp, dp + N, INF);
    dp[0] = 0;
    dfs(0, -1);

    rep(i, n) cout << ans[i] << "\n";
    return 0;
}
