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
using pl = pair<ll, ll>;

int solve() {
    int n, k;
    scanf(" %d %d", &n, &k);

    ll a, b, c, d;
    vector<ll> L(n), W(n), H(n);

    // read L
    rep(i, k) scanf(" %lld", &L[i]);

    scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
    for (int i = k; i < n; ++i)
        L[i] = (a * L[i - 2] + b * L[i - 1] + c) % d + 1;

    // read W
    rep(i, k) scanf(" %lld", &W[i]);

    scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
    for (int i = k; i < n; ++i)
        W[i] = (a * W[i - 2] + b * W[i - 1] + c) % d + 1;

    // read H
    rep(i, k) scanf(" %lld", &H[i]);

    scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
    for (int i = k; i < n; ++i)
        H[i] = (a * H[i - 2] + b * H[i - 1] + c) % d + 1;

    vector<ll> p(n);
    p[0] = (W[0] * 2 + H[0] * 2) % mod;

    set<pl> s;
    s.insert({L[0], L[0] + W[0]});
    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1];

        ll l = L[i], r = L[i] + W[i];

        ll nl = l, nr = r;
        auto itr = s.lower_bound({l, l});
        if (itr != s.begin()) {
            --itr;
            if (itr->se < l) ++itr;
        }

        ll sum_W = 0, ct = 0;
        while (itr != s.end()) {
            ll maxL = max(nl, itr->fi), minR = min(nr, itr->se);
            if (maxL <= minR) {
                nl = min(nl, itr->fi);
                nr = max(nr, itr->se);
                sum_W += itr->se - itr->fi;
                ++ct;
                itr = s.erase(itr);
            } else
                break;
        }
        s.insert({nl, nr});

        ll dx = nr - nl - sum_W;
        p[i] += 2 * dx;

        if (ct == 0)
            p[i] += 2 * H[i];
        else {
            p[i] -= (ct - 1) * 2 * H[i] % mod;
            p[i] += mod;
        }
        p[i] %= mod;
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
