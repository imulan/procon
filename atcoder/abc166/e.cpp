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

    map<int, int> pre, suf;
    rep(i, n) { ++suf[-a[i] + i]; }

    ll ans = 0;
    rep(i, n) {
        --suf[-a[i] + i];
        ans += pre[a[i] - i] + suf[a[i] + i];
        ++pre[-a[i] - i];
    }
    cout << ans / 2 << "\n";
    return 0;
}
