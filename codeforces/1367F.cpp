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

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> ua(a);
    sort(all(ua));
    ua.erase(unique(all(ua)), ua.end());
    rep(i, n) a[i] = lower_bound(all(ua), a[i]) - ua.begin();

    int A = ua.size();
    vector<vector<int>> pos(A);
    rep(i, n) pos[a[i]].pb(i);

    int mx = 1;
    vector<vector<int>> dp(n, vector<int>(3, -n));
    rep(i, n) {
        dp[i][0] = max(dp[i][0], 1);
        dp[i][2] = max(dp[i][2], 1);

        int sz = pos[a[i]].size();
        int idx = lower_bound(all(pos[a[i]]), i) - pos[a[i]].begin();

        if (idx > 0) {
            int pre = pos[a[i]][idx - 1];
            dp[i][0] = max(dp[i][0], dp[pre][0] + 1);
            dp[i][2] = max(dp[i][2], dp[pre][2] + 1);
        }

        int L = pos[a[i]].front(), R = pos[a[i]].back();
        if (a[i] > 0) {
            int add = 0;
            auto itr = lower_bound(all(pos[a[i] - 1]), i);
            if (itr != pos[a[i] - 1].begin()) {
                --itr;
                add = max(add, dp[*itr][0]);
                dp[i][2] = max(dp[i][2], dp[*itr][0] + 1);
            }

            int pre_R = pos[a[i] - 1].back();
            if (pre_R < i) {
                add = max(add, dp[pre_R][1]);
                dp[i][2] = max(dp[i][2], dp[pre_R][1] + 1);
            }
            if (i == L) dp[R][1] = max(dp[R][1], sz + add);
        }

        rep(j, 3) mx = max(mx, dp[i][j]);
    }
    return n - mx;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
