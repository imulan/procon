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
    int k, q;
    scanf(" %d %d", &k, &q);

    vector<int> d(k);
    rep(i, k) scanf(" %d", &d[i]);

    while (q--) {
        int n, x, m;
        scanf(" %d %d %d", &n, &x, &m);
        x %= m;

        int ans = n - 1;

        int L = n / k;
        ll add = 0;
        rep(i, k) {
            int ct = L;
            if (i == k - 1) {
                --ct;
                if ((n - 1) % k != k - 1) ++ct;
            } else {
                int r = (n - 1) % k;
                if (r != k - 1 && i < r) ++ct;
            }
            // printf(" %d : %d\n", i, ct);

            ll b = d[i] % m;
            if (b == 0) ans -= ct;
            add += b * ct;
        }
        ans -= (add + x) / m;
        printf("%d\n", ans);
    }
    return 0;
}
