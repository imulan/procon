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

using pl = pair<ll, ll>;

ll solve() {
    int n;
    scanf(" %d", &n);

    vector<pl> v(n);
    rep(i, n) {
        ll x, h;
        scanf(" %lld %lld", &x, &h);
        v[i] = {x, h};
    }
    sort(all(v));

    map<ll, int> X;
    rep(i, n) X[v[i].fi] = i;

    vector<ll> L(n), R(n);
    map<ll, ll> mL;
    ll ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        L[i] = max(L[i], v[i].se);
        ll x = v[i].fi - v[i].se;
        if (X.count(x)) {
            int idx = X[x];
            L[idx] = max(L[idx], L[i] + v[idx].se);
        }

        if (!mL.count(x)) mL[x] = L[i];
        mL[x] = max(mL[x], L[i]);

        ans = max(ans, L[i]);
    }

    rep(i, n) {
        R[i] = max(R[i], v[i].se);
        ll x = v[i].fi + v[i].se;
        if (X.count(x)) {
            int idx = X[x];
            R[idx] = max(R[idx], R[i] + v[idx].se);
        }

        ll add = 0;
        if (mL.count(x)) add = mL[x];

        ans = max(ans, R[i] + add);
    }

    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    rep(i, t) printf("Case #%d: %lld\n", i + 1, solve());
    return 0;
}
