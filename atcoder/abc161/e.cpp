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
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    vector<int> v;
    rep(i, n) if (s[i] == 'o') v.pb(i);

    vector<int> dp(n, -1);
    int mx = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'o') dp[i] = mx + 1;
        if (i + c < n) mx = max(mx, dp[i + c]);
    }

    int ct = 0, pre = -n;
    for (int i : v) {
        auto itr = upper_bound(all(v), max(i, pre + c));
        int x = 0;
        if (itr != v.end()) x = dp[*itr];

        if (ct + x < k) cout << i + 1 << "\n";

        if (i - pre > c) {
            ++ct;
            pre = i;
        }
    }
    return 0;
}
