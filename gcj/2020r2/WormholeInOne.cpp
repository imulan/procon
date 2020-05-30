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

#define X first
#define Y second

using P = pair<ll, ll>;

P calc_grad(P p, P q) {
    ll dx = p.X - q.X, dy = p.Y - q.Y;
    if (dx < 0) {
        dx = -dx;
        dy = -dy;
    }
    if (dx == 0 && dy < 0) dy = -dy;

    ll G = __gcd(abs(dx), abs(dy));
    return {dx / G, dy / G};
}

ll f(P grad, P p) { return grad.Y * p.X - grad.X * p.Y; }

int solve() {
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    map<P, unordered_set<int>> pts;
    rep(i, n) rep(j, i) {
        P grad = calc_grad(p[i], p[j]);
        pts[grad].insert(i);
        pts[grad].insert(j);
    }

    int ans = min(2, n);
    for (const auto& pp : pts) {
        P grad = pp.fi;

        map<ll, int> ct;
        for (int i : pp.se) ++ct[f(grad, p[i])];

        int C[2] = {};
        for (const auto& c : ct) C[c.se % 2] += c.se;
        int C_alone = n - C[0] - C[1];

        int add = min(2 - C[1] % 2, C_alone);
        ans = max(ans, C[0] + C[1] + add);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) printf("Case #%d: %d\n", i + 1, solve());
    return 0;
}
