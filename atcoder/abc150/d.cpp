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

ll lcm(ll x, ll y) { return x / __gcd(x, y) * y; }

ll solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] /= 2;
    }

    ll L = 1;
    rep(i, n) {
        L = lcm(L, a[i]);
        if (L > m) return 0;
    }
    rep(i, n) {
        ll q = L / a[i];
        if (q % 2 == 0) return 0;
    }

    ll x = m / L;
    return (x + 1) / 2;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
