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

using P = pair<ll, int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<ll> a(h - 1), b(w), c(h), d(w - 1);
    rep(i, h - 1) cin >> a[i];
    rep(i, w) cin >> b[i];
    rep(i, h) cin >> c[i];
    rep(i, w - 1) cin >> d[i];

    ll ans = 0;
    rep(i, w - 1) ans += c[0] + d[i];
    rep(i, h - 1) ans += a[i] + b[0];

    vector<P> v;
    for (int i = 1; i < w; ++i) {
        int val = a[0] + b[i] - (c[1] + d[i - 1]);
        v.pb({val, i});
    }
    sort(all(v));
    const int V = v.size();

    vector<ll> preb(V + 1), sufd(V + 1);
    rep(i, V) {
        int idx = v[i].se;
        preb[i + 1] = b[idx];
    }
    rep(i, V) {
        int idx = v[V - 1 - i].se;
        sufd[i + 1] = d[idx - 1];
    }
    rep(i, V) {
        preb[i + 1] += preb[i];
        sufd[i + 1] += sufd[i];
    }

    // dbg(v);
    // dbg(preb);
    // dbg(sufd);

    ll delta = 0;
    for (int i = 1; i < h; ++i) {
        int idx = lower_bound(all(v), P(-delta, 0)) - v.begin();

        ll bn = idx, dn = V - bn;
        ll add = preb[bn] + bn * a[i - 1] + sufd[dn] + dn * c[i];
        // // printf(" %d: (idx %d) delta %lld  // %lld %lld  add %lld\n", i,
        // idx, delta, bn, dn, add);

        ans += add;
        if (i + 1 < h) delta += a[i] - a[i - 1] - c[i + 1] + c[i];
    }
    cout << ans << "\n";
    return 0;
}
