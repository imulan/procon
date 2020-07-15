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

ll n, k;

ll G(ll x) {
    if (x > n) return 0;

    ll ret = 1;
    ll A = 1;
    while (1) {
        A *= 2;
        if (A * x > n) break;
        ll a = min(n - A * x, A - 1);
        ret += a + 1;
    }

    return ret;
}

ll F(ll x) {
    if (x > n) return 0;
    if (x % 2 == 1)
        return G(x);
    else
        return F(x + 1) + F(2 * x) + 1;
}

int main() {
    cin >> n >> k;

    ll ans = 1;
    rep(a, 2) {
        ll ok = 1, ng = n;
        while (ng - ok > 1) {
            ll m = (ng + ok) / 2;
            ll x = 2 * m - a;
            if (F(x) >= k)
                ok = m;
            else
                ng = m;
        }

        if (F(2 * ok - a) >= k) ans = max(ans, 2 * ok - a);
    }
    cout << ans << "\n";
    return 0;
}
