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

const int INF = 19191919;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> c(n);
    vector<vector<int>> a(n);
    rep(i, n) {
        cin >> c[i];
        a[i] = vector<int>(m);
        rep(j, m) cin >> a[i][j];
    }

    int ans = INF;
    rep(mask, 1 << n) {
        int cost = 0;
        vector<int> v(m);
        rep(i, n) if (mask >> i & 1) {
            cost += c[i];
            rep(j, m) v[j] += a[i][j];
        }
        bool ok = true;
        rep(i, m) if (v[i] < x) ok = false;
        if (ok) ans = min(ans, cost);
    }
    if (ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
