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
    int n, q;
    scanf(" %d %d", &n, &q);

    vector<ll> h(n);
    rep(i, n) scanf(" %lld", &h[i]);

    map<ll, int> m;

    auto ADD = [&](int idx, int add) {
        if (idx < 0 || n <= idx + 1) return;

        ll val = h[idx + 1] - h[idx];
        if (idx % 2 == 1) val *= -1;
        m[val] += add;
    };

    rep(i, n - 1) ADD(i, 1);

    ll e = 0, o = 0;
    rep(qi, q) {
        int t;
        scanf(" %d", &t);

        ll v;
        if (t == 1) {
            scanf(" %lld", &v);
            e += v;
        } else if (t == 2) {
            scanf(" %lld", &v);
            o += v;
        } else {
            int u;
            scanf(" %d %lld", &u, &v);
            --u;

            for (int i : {-1, 0}) ADD(u + i, -1);
            h[u] += v;
            for (int i : {-1, 0}) ADD(u + i, 1);
        }

        int ans = 0;
        if (m.count(e - o)) ans = m[e - o];
        printf("%d\n", ans);
    }

    return 0;
}
