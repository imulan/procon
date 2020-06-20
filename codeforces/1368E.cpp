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

void solve() {
    int n, m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    rep(i, m) {
        int x, y;
        scanf(" %d %d", &x, &y);
        G[x - 1].pb(y - 1);
    }

    vector<int> dp(n);
    vector<int> ans;
    rep(i, n) {
        if (dp[i] == 0)
            for (int j : G[i]) dp[j] |= 1;
        else if (dp[i] == 1)
            for (int j : G[i]) dp[j] |= 2;
        else
            ans.pb(i);
    }

    int A = ans.size();
    printf("%d\n", A);
    rep(i, A) printf("%d%c", ans[i] + 1, " \n"[i == A - 1]);
}

int main() {
    int t;
    scanf(" %d", &t);
    rep(i, t) solve();
    return 0;
}
