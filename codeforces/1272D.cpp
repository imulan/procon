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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> l(n, 1), r(n, 1);
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] < a[i]) l[i] = l[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) r[i] = r[i + 1] + 1;
    }

    int ans = 1;
    rep(i, n) ans = max({ans, l[i], r[i]});

    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i + 1]) ans = max(ans, l[i - 1] + r[i + 1]);
    }

    cout << ans << "\n";
    return 0;
}
