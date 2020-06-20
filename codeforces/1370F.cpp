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

const int N = 1000;
vector<int> G[N];
int d[N][N];

void init() {
    rep(i, N) G[i].clear();
    rep(i, N) rep(j, N) d[i][j] = 0;
}

void dfs(int v, int p, int root) {
    for (int e : G[v])
        if (e != p) {
            d[root][e] = d[root][v] + 1;
            dfs(e, v, root);
        }
}

using pi = pair<int, int>;

pi ask(const vector<int>& a) {
    int A = a.size();
    cout << "? " << A;
    rep(i, A) cout << " " << a[i] + 1;
    cout << endl;

    int x, y;
    cin >> x >> y;
    if (x == -1) assert(false);
    return {x - 1, y};
}

void answer(int x, int y) {
    cout << "! " << x + 1 << " " << y + 1 << endl;

    string jd;
    cin >> jd;
    assert(jd == "Correct");
}

void solve() {
    init();

    int n;
    cin >> n;

    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    rep(i, n) dfs(i, -1, i);

    vector<int> ALL(n);
    rep(i, n) ALL[i] = i;
    pi p = ask(ALL);
    int x = p.fi, D = p.se;

    int L = x, R = x;
    while (d[L][R] < D) {
        int r = (D - d[L][R] + 1) / 2;
        vector<int> cand;
        rep(i, n) {
            if (d[L][i] == r && d[R][i] == d[L][R] + r)
                cand.pb(i);
            else if (d[R][i] == r && d[L][i] == d[L][R] + r)
                cand.pb(i);
        }

        p = ask(cand);
        int y = p.fi;
        if (d[L][y] == r && d[R][y] == d[L][R] + r)
            L = y;
        else
            R = y;
    }

    answer(L, R);
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}
