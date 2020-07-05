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
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> ct(k);
    int one = 0;
    rep(i, n) {
        if (s[i] == '1') {
            ++one;
            ++ct[i % k];
        }
    }

    auto calc = [&](const vector<int>& v) {
        int V = v.size();

        vector<int> dp(3, V);
        dp[0] = 0;
        rep(i, V) {
            vector<int> nx(3, V);
            rep(j, 3) {
                int val = (j == 1);
                int add = (v[i] != val);
                nx[j] = min(nx[j], dp[j] + add);

                if (j + 1 < 3) {
                    val = (j + 1 == 1);
                    add = (v[i] != val);
                    nx[j + 1] = min(nx[j + 1], dp[j] + add);
                }
            }
            swap(dp, nx);
        }

        int cost = V;
        rep(i, 3) cost = min(cost, dp[i]);
        return cost;
    };

    int ans = max(0, one - 1);
    rep(i, k) {
        int t = one - ct[i];

        vector<int> v;
        for (int j = i; j < n; j += k) v.pb(s[j] - '0');

        int cost = calc(v);
        t += cost;
        ans = min(ans, t);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
