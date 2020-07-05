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

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int P = 2 * k + 2;
    vector<int> p(P), ct(P);

    rep(i, n / 2) {
        int x = min(a[i], a[n - 1 - i]), y = max(a[i], a[n - 1 - i]);

        ++ct[x + y];
        ++p[x + 1];
        --p[k + y + 1];
    }
    rep(i, P - 1) p[i + 1] += p[i];

    int ans = n;
    for (int x = 2; x <= 2 * k; ++x) ans = min(ans, n - ct[x] - p[x]);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
