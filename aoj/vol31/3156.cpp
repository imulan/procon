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
    ll n;
    cin >> n;

    ll ans = 0;
    rep(i, 40) {
        ll p = 1LL << i;
        ll X = p * (n / p);
        if (X == 0) break;

        ll t = 0, pre = 0, now = X;
        while (1) {
            t += now;

            ll nx = pre + now;
            if (nx % 2 != 0) break;
            nx /= 2;

            pre = now;
            now = nx;
        }
        ans = max(ans, t);
    }
    cout << ans << "\n";
    return 0;
}
