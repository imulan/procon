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

ll d(ll x) {
    ll ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

ll solve() {
    ll n, s;
    cin >> n >> s;

    ll x = n;
    ll add = 1;
    while (d(x) > s) {
        ll na = add * 10;
        if (x % na == 0) add = na;
        x += add;
    }
    return x - n;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
