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

const int A = 20;
const ll mod = 1e9;

int main() {
    int k;
    scanf(" %d", &k);

    vector<vector<ll>> ct(k);
    vector<ll> inv(k);

    rep(i, k) {
        int n;
        scanf(" %d", &n);
        vector<int> a(n);
        rep(j, n) {
            scanf(" %d", &a[j]);
            --a[j];
        }

        vector<ll> x(A);
        rep(j, n) {
            ++x[a[j]];
            for (int e = a[j] + 1; e < A; ++e) inv[i] += x[e];
            inv[i] %= mod;
        }
        ct[i] = x;
    }

    ll ans = 0;
    vector<ll> now(A);

    int Q;
    scanf(" %d", &Q);
    rep(q, Q) {
        int b;
        scanf(" %d", &b);
        --b;

        ll s = 0;
        for (int i = A - 1; i >= 0; --i) {
            (ans += ct[b][i] * s) %= mod;
            (s += now[i]) %= mod;
            (now[i] += ct[b][i]) %= mod;
        }
        (ans += inv[b]) %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}
