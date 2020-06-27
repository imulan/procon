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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> pre(a);
    rep(i, n - 1) pre[i + 1] += pre[i];

    map<ll, int> m;
    m[0] = -1;

    ll ans = 0;
    int mx = -2;
    rep(i, n) {
        int idx = -2;
        if (m.count(pre[i])) idx = m[pre[i]];
        ++idx;

        mx = max(mx, idx);
        ans += i - mx;

        m[pre[i]] = i;
    }
    cout << ans << "\n";
    return 0;
}
