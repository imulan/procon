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

ll f(ll x) { return x * (x + 1) / 2; }

int main() {
    int n;
    cin >> n;

    ll ans = 0;
    rep(i, n) ans += f(n - i);

    rep(i, n - 1) {
        ll u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        ans -= u * (n + 1 - v);
    }
    cout << ans << "\n";
    return 0;
}
