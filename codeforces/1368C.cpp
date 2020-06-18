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

using pi = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<pi> ans;
    for (int i = -1; i < 2 * n; ++i) ans.pb({i, 0});
    rep(i, n) {
        for (int j : {1, -1}) ans.pb({2 * i, j});
    }

    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            for (int j : {2, -2}) {
                rep(k, 3) ans.pb({2 * i + k, j});
            }
        }

        int l = -2, r = 2 * n;
        for (int i : {l, r}) rep(j, 5) ans.pb({i, j});
        for (int i = l + 1; i < r; ++i) ans.pb({i, 4});
    } else {
        for (int i = 0; i + 1 < n; i += 2) rep(k, 3) ans.pb({2 * i + k, 2});
        for (int i = 1; i + 1 < n; i += 2) rep(k, 3) ans.pb({2 * i + k, -2});

        rep(i, 3) ans.pb({-2, -i});
        rep(i, 2) ans.pb({-i, -2});

        rep(i, 3) ans.pb({2 * n, i});
        for (int i = 1; i <= 2; ++i) ans.pb({2 * n - i, 2});
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());

    cout << ans.size() << "\n";
    for (const auto& p : ans) cout << p.fi << " " << p.se << "\n";
    return 0;
}
