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

const ll INF = LLONG_MAX / 3;

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);

    vector<int> x[4];
    rep(i, n) {
        int t, a, b;
        scanf(" %d %d %d", &t, &a, &b);
        x[(a << 1) | b].pb(t);
    }
    rep(i, 4) sort(all(x[i]));

    int common = x[3].size();
    int alice = x[2].size(), bob = x[1].size();

    vector<ll> A(alice + 1), B(bob + 1);
    rep(i, alice) A[i + 1] = A[i] + x[2][i];
    rep(i, bob) B[i + 1] = B[i] + x[1][i];

    ll ans = INF;
    ll tc = 0;
    rep(i, common + 1) {
        if (i > k) break;
        int r = k - i;
        if (r <= alice && r <= bob) ans = min(ans, tc + A[r] + B[r]);

        if (i < common) tc += x[3][i];
    }

    if (ans == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
