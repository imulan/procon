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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto check = [&](ll x) {
        ll ct = 0;
        for (int L : a) {
            ll num = (L + x - 1) / x;
            ct += num - 1;
        }
        return ct <= k;
    };

    ll ng = 0, ok = 1000000000;
    while (ok - ng > 1) {
        ll mid = (ng + ok) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
