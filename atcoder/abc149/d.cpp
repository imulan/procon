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

int main() {
    int n, k, p[3];
    cin >> n >> k;
    rep(i, 3) cin >> p[i];

    string t;
    cin >> t;

    vector<int> v(n);
    rep(i, n) {
        if (t[i] == 'r') v[i] = 2;
        if (t[i] == 's') v[i] = 0;
        if (t[i] == 'p') v[i] = 1;
    }

    int ans = 0;
    rep(i, k) {
        vector<int> dp(3);
        dp[v[i]] = p[v[i]];

        for (int j = i + k; j < n; j += k) {
            vector<int> nx(3);
            rep(x, 3) rep(y, 3) {
                if (x == y) continue;
                int add = 0;
                if (x == v[j]) add = p[x];
                nx[x] = max(nx[x], dp[y] + add);
            }
            swap(dp, nx);
        }

        int add = 0;
        for (int j : dp) add = max(add, j);
        ans += add;
    }
    cout << ans << "\n";
    return 0;
}
