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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(all(p), greater<ll>());
    sort(all(q), greater<ll>());

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, x) pq.push(p[i]);
    rep(i, y) pq.push(q[i]);

    for (ll i : r) {
        ll v = pq.top();
        pq.pop();
        pq.push(max(v, i));
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
    return 0;
}
