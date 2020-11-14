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

struct UF {
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N) : n(N), d(N, -1) {}
    int root(int v) {
        if (d[v] < 0) return v;
        return d[v] = root(d[v]);
    }
    bool unite(int X, int Y) {
        X = root(X);
        Y = root(Y);
        if (X == Y) return false;
        if (size(X) < size(Y)) swap(X, Y);
        d[X] += d[Y];
        d[Y] = X;
        return true;
    }
    int size(int v) { return -d[root(v)]; }
    bool same(int X, int Y) { return root(X) == root(Y); }
};

void solve() {
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i, n) scanf(" %d", &a[i]);

    vector<pair<int, int>> v;
    UF uf(n);
    rep(i, n) rep(j, i) {
        if (a[i] != a[j] && uf.unite(i, j)) v.pb({j, i});
    }

    if (uf.size(0) != n) {
        printf("NO\n");
        return;
    }

    printf("YES\n");
    for (const auto& p : v) printf("%d %d\n", p.fi + 1, p.se + 1);
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) solve();
    return 0;
}
