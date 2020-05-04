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

const ll INF = LLONG_MAX / 3;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> c(n), d(n);
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> d[i];

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    rep(i, n) {
        vector<ll> nx(n + 1, INF);
        rep(j, n) if (dp[j] < INF) {
            // insert (
            nx[j + 1] = min(nx[j + 1], dp[j] + c[i] * (s[i] != '('));
            // insert )
            if (j - 1 >= 0)
                nx[j - 1] = min(nx[j - 1], dp[j] + c[i] * (s[i] != ')'));
            // delete
            nx[j] = min(nx[j], dp[j] + d[i]);
        }
        swap(dp, nx);
    }

    cout << dp[0] << "\n";
    return 0;
}
