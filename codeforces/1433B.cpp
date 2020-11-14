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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int l = 0, r = n - 1;
    while (a[l] == 0) ++l;
    while (a[r] == 0) --r;
    int ans = 0;
    for (int i = l; i <= r; ++i) ans += (!a[i]);
    return ans;
}

int main() {
    int t;
    cin >> t;
    rep(tt, t) cout << solve() << "\n";
    return 0;
}
