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

const int A = 26;

int solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> ct(A);
    for (char c : s) ++ct[c - 'a'];
    sort(all(ct), greater<int>());

    for (int L = n; L > 0; --L) {
        vector<vector<int>> G(L);
        rep(i, L) {
            int j = (i + k) % L;
            if (i != j) {
                G[i].pb(j);
                G[j].pb(i);
            }
        }

        vector<int> x;
        vector<bool> vis(L);
        rep(i, L) if (!vis[i]) {
            queue<int> que({i});
            vis[i] = true;
            int cc = 1;
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (int e : G[v])
                    if (!vis[e]) {
                        que.push(e);
                        ++cc;
                        vis[e] = true;
                    }
            }
            x.pb(cc);
        }

        int X = x.size();
        vector<int> t(ct);
        int ti = 0;
        rep(i, X) {
            assert(x[i] == x[0]);
            while (ti < A && t[ti] < x[i]) ++ti;
            if (ti == A) break;

            t[ti] -= x[i];
        }
        if (ti < A) return L;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
