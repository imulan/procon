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

const ll mod = 1e9 + 7;

int solve() {
    int n, k, w;
    scanf(" %d %d %d", &n, &k, &w);

    ll a, b, c, d;
    vector<ll> L(n), H(n);

    rep(i, k) scanf(" %lld", &L[i]);

    scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
    for (int i = k; i < n; ++i)
        L[i] = (a * L[i - 2] + b * L[i - 1] + c) % d + 1;

    rep(i, k) scanf(" %lld", &H[i]);

    scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
    for (int i = k; i < n; ++i)
        H[i] = (a * H[i - 2] + b * H[i - 1] + c) % d + 1;

    unordered_map<ll, ll> X;
    auto ADD = [&](ll pos, ll h) {
        for (ll i = pos; i <= pos + w; ++i) {
            if (!X.count(i)) X[i] = 0;
            X[i] = max(X[i], h);
        }
    };

    vector<ll> p(n);
    p[0] = 2 * w + 2 * H[0];
    p[0] %= mod;
    ADD(L[0], H[0]);

    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1];

        if (L[i] - L[i - 1] <= w) {
            ll dx = L[i] - L[i - 1];
            p[i] += 2 * dx;

            ll h = X[L[i]];
            if (H[i] > h) p[i] += 2 * (H[i] - h);
        } else {
            p[i] += 2 * w + 2 * H[i];
        }

        p[i] %= mod;
        ADD(L[i], H[i]);
    }
    // dbg(p);
    ll ans = 1;
    rep(i, n)(ans *= p[i]) %= mod;
    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    rep(i, t) printf("Case #%d: %d\n", i + 1, solve());
    return 0;
}
