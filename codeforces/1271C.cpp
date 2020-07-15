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
    int n, sx, sy;
    cin >> n >> sx >> sy;

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    int ans = 0, ax = -1, ay = -1;
    rep(f, 2) {
        int L = 0, R = 0;
        rep(i, n) {
            if (x[i] <= sx - 1) ++L;
            if (sx + 1 <= x[i]) ++R;
        }

        if (max(L, R) > ans) {
            ans = max(L, R);
            if (L > R)
                ax = sx - 1;
            else
                ax = sx + 1;

            ay = sy;
            if (f) swap(ax, ay);
        }
        if (L < R) ans = max({ans, L, R});

        swap(sx, sy);
        rep(i, n) swap(x[i], y[i]);
    }

    cout << ans << "\n";
    cout << ax << " " << ay << "\n";
    return 0;
}
