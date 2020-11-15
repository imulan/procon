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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sa = 0;
    rep(i, n) {
        cin >> a[i];
        sa += a[i];
    }

    rep(i, n) a.pb(a[i]);

    ll ans = sa;
    ll x = 0;
    int r = 0;
    rep(i, n) {
        if (r == i) x += a[r++];
        while (r < 2 * n && x <= sa - x) {
            ans = min(ans, abs(x - (sa - x)));
            x += a[r++];
        }
        ans = min(ans, abs(x - (sa - x)));

        x -= a[i];
    }

    cout << ans << "\n";
    return 0;
}
