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

pi solve() {
    int h, w;
    cin >> h >> w;

    int n = h * w;

    vector<bool> black(n);
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) black[w * i + j] = (s[j] == '0');
    }

    vector<int> nxt(n);
    vector<vector<int>> inv(n);
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            int y = i, x = j;
            if (s[j] == 'L')
                --x;
            else if (s[j] == 'R')
                ++x;
            else if (s[j] == 'U')
                --y;
            else
                ++y;

            int u = w * i + j, v = w * y + x;
            nxt[u] = v;
            inv[v].pb(u);
        }
    }

    int mx = 0, mxb = 0;
    vector<bool> vis(n);
    vector<int> col(n, -1);
    rep(i, n) if (!vis[i]) {
        vector<int> v;
        int now = i;
        while (!vis[now]) {
            vis[now] = true;
            v.pb(now);
            now = nxt[now];
        }

        int sz = v.size();
        int start = 0;
        while (v[start] != now) ++start;

        int L = sz - start;
        vector<int> cc;
        queue<int> que;
        for (int j = start; j < sz; ++j) {
            que.push(v[j]);
            cc.pb(v[j]);
            col[v[j]] = j - start;
        }

        while (!que.empty()) {
            int x = que.front();
            que.pop();

            int nx_col = (col[x] - 1 + L) % L;
            for (int j : inv[x]) {
                if (col[j] == -1) {
                    que.push(j);
                    cc.pb(j);
                    col[j] = nx_col;
                }
            }
        }

        vector<int> has_black(L);
        for (int j : cc) {
            vis[j] = true;
            has_black[col[j]] |= black[j];
        }

        int b_ct = 0;
        for (int j : has_black) b_ct += j;

        mx += L;
        mxb += b_ct;
    }

    return {mx, mxb};
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        pi ans = solve();
        cout << ans.fi << " " << ans.se << "\n";
    }
    return 0;
}
