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
    ll x, y, n;
    scanf(" %lld %lld %lld", &x, &y, &n);

    // k = t*x+y <= n
    // t <= (n-y)/x
    ll t = (n - y) / x;
    return t * x + y;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%lld\n", solve());
    return 0;
}
