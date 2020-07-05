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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    while (k--) {
        sort(all(a));
        sort(all(b));
        if (a[0] < b[n - 1]) swap(a[0], b[n - 1]);
    }

    int s = 0;
    for (int i : a) s += i;
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
