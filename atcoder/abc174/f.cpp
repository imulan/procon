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

const int INF = 19191919;

using vi = vector<int>;

struct SegTree {
    int n;
    vector<vi> dat;
    // 初期化
    SegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<vi>(2 * n - 1);
    }

    vi merge(const vi& a, const vi& b) {
        int A = a.size(), B = b.size();
        int ai = 0, bi = 0;
        vi ret;
        while (ai < A || bi < B) {
            bool isA = true;
            if (ai == A)
                isA = false;
            else if (bi == B)
                isA = true;
            else {
                if (a[ai] > b[bi]) isA = false;
            }

            if (isA)
                ret.pb(a[ai++]);
            else
                ret.pb(b[bi++]);
        }
        return ret;
    }

    void init(const vi& v) {
        int V = v.size();
        rep(i, V) dat[i + n - 1] = {v[i]};
        for (int i = V + n - 1; i < 2 * n - 1; ++i) dat[i] = {0};

        for (int i = n - 2; i >= 0; --i)
            dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]);
    }

    int _query(int a, int b, int val, int k, int l, int r) {
        if (r <= a || b <= l) return 0;

        if (a <= l && r <= b) {
            int sz = dat[k].size();
            int idx = upper_bound(all(dat[k]), val) - dat[k].begin();
            return sz - idx;
        }
        int vl = _query(a, b, val, 2 * k + 1, l, (l + r) / 2);
        int vr = _query(a, b, val, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
    // [a,b)
    int query(int a, int b, int val) { return _query(a, b, val, 0, 0, n); }
};

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);

    vector<vector<int>> pos(n);
    rep(i, n) {
        int c;
        scanf(" %d", &c);
        pos[c - 1].pb(i);
    }

    vector<int> nx(n, INF);
    rep(i, n) {
        int sz = pos[i].size();
        rep(j, sz - 1) {
            int u = pos[i][j], v = pos[i][j + 1];
            nx[u] = v;
        }
    }

    SegTree st(n);
    st.init(nx);

    while (q--) {
        int l, r;
        scanf(" %d %d", &l, &r);
        --l;
        --r;
        printf("%d\n", st.query(l, r + 1, r));
    }

    return 0;
}
