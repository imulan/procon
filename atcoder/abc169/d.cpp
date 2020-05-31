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

map<ll, int> factorize(ll x) {
    map<ll, int> ret;
    ll t = x;
    for (ll i = 2; i * i <= x; ++i) {
        while (t % i == 0) {
            t /= i;
            ++ret[i];
        }
    }
    if (t > 1) ++ret[t];
    return ret;
}

int main() {
    ll n;
    cin >> n;

    map<ll, int> m = factorize(n);

    ll ans = 0;
    for (const auto& x : m) {
        int ct = x.se;

        int i = 1;
        while (1) {
            if (ct - i >= 0) {
                ct -= i;
                ++ans;
                ++i;
            } else
                break;
        }
    }
    cout << ans << "\n";
    return 0;
}
