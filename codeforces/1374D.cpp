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
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);

    map<ll, ll> ct;
    rep(i, n) {
        ll a;
        scanf(" %lld", &a);
        ++ct[a % k];
    }

    ll ans = 0;
    for (const auto& p : ct) {
        ll rem = p.fi, num = p.se;
        if (rem == 0) continue;
        ll x = k - rem;
        ll mx = (num - 1) * k + x;

        // printf(" (%lld %lld),  x %lld\n", rem, num, x);
        ans = max(ans, mx + 1);
    }
    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%lld\n", solve());
    return 0;
}
