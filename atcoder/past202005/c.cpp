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
    const ll LIM = 1e9;

    ll a, r, n;
    cin >> a >> r >> n;

    ll x = a;
    if (r != 1) {
        rep(i, n - 1) {
            x *= r;
            if (x > LIM) break;
        }
    }

    if (x > LIM)
        cout << "large\n";
    else
        cout << x << "\n";

    return 0;
}
