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
    int n, p;
    string s;
    cin >> n >> p >> s;

    ll ans = 0;
    if (p == 2 || p == 5) {
        rep(i, n) {
            int x = s[i] - '0';
            if (x % p == 0) ans += i + 1;
        }
    } else {
        vector<int> pw(n);
        pw[0] = 1;
        for (int i = 1; i < n; ++i) pw[i] = (pw[i - 1] * 10) % p;

        vector<int> x(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            x[i] = x[i + 1] + pw[n - 1 - i] * (s[i] - '0');
            x[i] %= p;
        }

        vector<ll> ct(p);
        for (int i : x) ++ct[i];

        for (ll i : ct) ans += i * (i - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
