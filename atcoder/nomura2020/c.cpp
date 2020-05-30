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

const ll INF = LLONG_MAX / 10;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, n + 1) cin >> a[i];

    vector<ll> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ll r = p[i - 1] - a[i - 1];
        if (r <= 0) {
            cout << -1 << "\n";
            return 0;
        }
        p[i] = min(r * 2, INF);
    }

    rep(i, n + 1) {
        if (p[i] < a[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    vector<ll> s(a);
    for (int i = n - 1; i >= 0; --i) s[i] += s[i + 1];

    ll ans = 0;
    rep(i, n + 1) ans += min(p[i], s[i]);
    cout << ans << "\n";
    return 0;
}
