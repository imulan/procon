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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int mx = 19191919;
    vector<int> a;
    rep(yi, n) rep(xi, yi) {
        int d = y - x;
        if (d % (yi - xi) != 0) continue;
        d /= (yi - xi);

        vector<int> t(n);
        t[xi] = x;
        t[yi] = y;
        for (int i = xi - 1; i >= 0; --i) t[i] = t[i + 1] - d;
        for (int i = xi + 1; i < n; ++i) t[i] = t[i - 1] + d;
        if (t[0] > 0 && t[n - 1] < mx) {
            mx = t[n - 1];
            a = t;
        }
    }

    rep(i, n) cout << a[i] << " \n"[i == n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
