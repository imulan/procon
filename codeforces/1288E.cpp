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

struct BIT {
    // [1,n]
    int n;
    vector<ll> bit;
    // 初期化
    BIT(int _n) {
        n = _n;
        bit = vector<ll>(n + 1, 0);
    }
    // sum of [1,i]
    ll sum(int i) {
        ll s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

using pi = pair<int, int>;
using P = pair<pi, int>;

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);

    vector<int> mn(n), mx(n);
    rep(i, n) mn[i] = mx[i] = i;

    vector<int> x;
    int X = n + m;
    x.reserve(X);
    for (int i = n - 1; i >= 0; --i) x.pb(i);

    rep(i, m) {
        int a;
        scanf(" %d", &a);
        --a;
        mn[a] = 0;
        x.pb(a);
    }

    vector<vector<int>> pos(n);
    rep(i, X) pos[x[i]].pb(i);
    rep(i, n) pos[i].pb(X);

    vector<P> query;
    BIT b(X + 1);
    vector<int> sz(n);

    rep(i, n) {
        sz[i] = pos[i].size();
        rep(j, sz[i] - 1) query.pb({{pos[i][j], pos[i][j + 1]}, i});

        if (sz[i] > 0) b.add(pos[i][0] + 1, 1);
    }
    sort(all(query));
    int Q = query.size();

    vector<int> idx(n);
    int qi = 0;
    rep(i, X) {
        int val = x[i];

        b.add(pos[val][idx[val]] + 1, -1);
        ++idx[val];
        b.add(pos[val][idx[val]] + 1, 1);

        while (qi < Q) {
            P pp = query[qi];
            int l = pp.fi.fi, r = pp.fi.se, v = pp.se;
            if (l != i) break;

            int t = b.sum(r) - b.sum(l + 1);
            mx[v] = max(mx[v], t);
            ++qi;
        }
    }

    rep(i, n) printf("%d %d\n", mn[i] + 1, mx[i] + 1);
    return 0;
}
