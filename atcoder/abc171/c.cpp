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
    --n;

    int ct = 1;
    ll X = 26;
    while (n >= X) {
        n -= X;
        X *= 26;
        ++ct;
    }

    string ans = "";
    rep(i, ct) {
        ans += 'a' + n % 26;
        n /= 26;
    }
    reverse(all(ans));
    cout << ans << "\n";
    return 0;
}
