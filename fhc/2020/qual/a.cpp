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

void solve() {
    int n;
    string I, O;
    cin >> n >> I >> O;

    vector<vector<int>> G(n);
    rep(u, n) {
        for (int i : {-1, 1}) {
            int v = u + i;
            if (v < 0 || n <= v) continue;
            if (O[u] == 'Y' && I[v] == 'Y') G[u].pb(v);
        }
    }

    rep(i, n) {
        vector<bool> vis(n);
        vis[i] = true;
        queue<int> que({i});
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int e : G[v])
                if (!vis[e]) {
                    vis[e] = true;
                    que.push(e);
                }
        }

        rep(j, n) cout << (vis[j] ? 'Y' : 'N');
        cout << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        printf("Case #%d:\n", i + 1);
        solve();
    }
    return 0;
}
