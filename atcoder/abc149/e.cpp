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
    ll m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    vector<ll> suf(n + 1);
    rep(i, n) suf[i + 1] = a[n - 1 - i];
    rep(i, n) suf[i + 1] += suf[i];

    // lb以上
    auto calc = [&](ll lb) {
        vector<int> ct(n);
        rep(i, n) {
            // a[i]+x >= lb
            // x >= lb-a[i]
            int idx = lower_bound(all(a), lb - a[i]) - a.begin();
            ct[i] = n - idx;
        }
        return ct;
    };

    ll ng = 0, ok = 222222;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;

        vector<int> v = calc(mid);
        ll s = 0;
        for (int i : v) s += i;

        if (s <= m)
            ok = mid;
        else
            ng = mid;
    }

    vector<int> x = calc(ok);
    ll sx = 0;
    for (int i : x) sx += i;

    ll ans = (ok - 1) * (m - sx);
    rep(i, n) {
        ans += a[i] * x[i];
        ans += suf[x[i]];
    }
    cout << ans << "\n";
    return 0;
}
