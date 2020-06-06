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
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> G(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> c(n);
    rep(i, n) cin >> c[i];

    rep(query, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;

            cout << c[x] << "\n";
            for (int nx : G[x]) c[nx] = c[x];
        } else {
            int x, y;
            cin >> x >> y;
            --x;

            cout << c[x] << "\n";
            c[x] = y;
        }
    }

    return 0;
}
