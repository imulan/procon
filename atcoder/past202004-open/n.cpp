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

using pi = pair<int, int>;
using P = pair<pi, int>;

const ll INF = LLONG_MAX / 3;

struct LazySegTree {
    int n;
    vector<ll> dat, lazy;
    //初期化
    LazySegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<ll>(2 * n - 1, 0);
        lazy = vector<ll>(2 * n - 1, 0);
    }
    void setLazy(int k, ll v, int l, int r) {
        lazy[k] += v;
        dat[k] += v * (r - l);
    }
    void push(int k, int l, int r) {
        if (lazy[k] != 0) {
            setLazy(2 * k + 1, lazy[k], l, (l + r) / 2);
            setLazy(2 * k + 2, lazy[k], (l + r) / 2, r);
        }
        lazy[k] = 0;
    }
    void fix(int k, int l, int r) { dat[k] = dat[2 * k + 1] + dat[2 * k + 2]; }
    ll merge(ll x, ll y) { return x + y; }
    //内部的に投げられるクエリ
    void _add(int a, int b, ll x, int k, int l, int r) {
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            setLazy(k, x, l, r);
            return;
        }

        push(k, l, r);
        _add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        _add(a, b, x, 2 * k + 2, (l + r) / 2, r);

        fix(k, l, r);
    }
    //[a,b)に+x
    void add(int a, int b, ll x) { return _add(a, b, x, 0, 0, n); }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return dat[k];

        push(k, l, r);
        ll vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return merge(vl, vr);
    }
    //[a,b)の最小値
    ll query(int a, int b) { return _query(a, b, 0, 0, n); }
};

struct D {
    ll l, r, c;
};

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);

    map<ll, vector<D>> X;
    vector<ll> ux, uy;

    rep(i, n) {
        ll x, y, d, c;
        scanf(" %lld %lld %lld %lld", &x, &y, &d, &c);
        X[x].pb({y, y + d + 1, c});
        X[x + d + 1].pb({y, y + d + 1, -c});

        ux.pb(x);
        ux.pb(x + d + 1);
        uy.pb(y);
        uy.pb(y + d + 1);
    }
    ux.pb(-INF);
    ux.pb(INF);
    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());

    uy.pb(-INF);
    uy.pb(INF);
    sort(all(uy));
    uy.erase(unique(all(uy)), uy.end());

    auto FIND_Y = [&](ll y) { return lower_bound(all(uy), y) - uy.begin(); };

    vector<P> query(q);
    rep(i, q) {
        int a, b;
        scanf(" %d %d", &a, &b);
        query[i] = {{a, b}, i};
    }
    sort(all(query));

    const int Y = uy.size();
    LazySegTree st(Y);

    vector<ll> ans(q);
    int qi = 0;
    for (ll x : ux) {
        // query
        while (qi < q) {
            int qx = query[qi].fi.fi, qy = query[qi].fi.se;
            int idx = query[qi].se;
            if (qx >= x) break;

            int yi = upper_bound(all(uy), qy) - uy.begin() - 1;
            ans[idx] = st.query(yi, yi + 1);

            ++qi;
        }

        for (const auto& a : X[x]) {
            int ly = FIND_Y(a.l), ry = FIND_Y(a.r);
            st.add(ly, ry, a.c);
        }
    }

    for (ll i : ans) printf("%lld\n", i);
    return 0;
}
