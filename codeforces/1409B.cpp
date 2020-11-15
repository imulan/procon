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

ll solve() {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll ans = a * b;
    rep(loop, 2) {
        ll A = a, B = b;

        if (A - n > x) {
            A -= n;
        } else {
            // A-n <= x
            // A-x <= n
            ll rem = n - (A - x);
            A = x;
            B = max(y, B - rem);
        }

        // printf(" %lld  * %lld\n", A, B);
        ans = min(ans, A * B);

        swap(a, b);
        swap(x, y);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
