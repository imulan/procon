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

struct SegTree {
    int n;
    vector<pi> dat;
    // 初期化
    SegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat = vector<pi>(2 * n - 1, pi(0, 0));

        rep(i, n) dat[i + n - 1] = {0, i};
        for (int i = n - 2; i >= 0; --i)
            dat[i] = max(dat[2 * i + 1], dat[2 * i + 2]);
    }
    // k番目(0-indexed)の値を+a
    void add(int k, int a) {
        k += n - 1;
        dat[k].fi += a;
        //更新
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // 内部的に投げられるクエリ
    pi _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return {-1, 0};

        if (a <= l && r <= b) return dat[k];

        pi vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        pi vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
    // [a,b)
    pi query(int a, int b) { return _query(a, b, 0, 0, n); }
};

int solve() {
    int n, k;
    scanf(" %d %d", &n, &k);

    vector<set<int>> G(n);
    rep(i, n - 1) {
        int x, y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].insert(y);
        G[y].insert(x);
    }

    if (k == 1) return n - 1;

    SegTree st(n);
    vector<queue<int>> leaves(n);
    vector<int> deg(n);
    rep(i, n) {
        if (G[i].size() == 1) {
            int u = *G[i].begin();
            leaves[u].push(i);
            st.add(u, 1);
        }
    }

    int ans = 0;
    while (1) {
        pi p = st.query(0, n);
        if (p.fi < k) break;
        ++ans;
        int v = p.se;
        rep(loop, k) {
            int u = leaves[v].front();
            leaves[v].pop();
            G[v].erase(u);
            G[u].erase(v);
        }
        st.add(v, -k);

        if (G[v].size() == 1) {
            int u = *G[v].begin();
            leaves[u].push(v);
            st.add(u, 1);
        }
    }

    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%d\n", solve());
    return 0;
}
