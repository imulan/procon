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
    int n;
    cin >> n;

    vector<queue<int>> q(n);
    map<int, int> pos;

    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int t;
            cin >> t;

            pos[t] = i;
            q[i].push(t);
        }
    }

    int m;
    cin >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    set<int> s[2];
    rep(i, 2) s[i].insert(0);

    vector<vector<int>> x(n, vector<int>(2));
    rep(i, n) {
        rep(j, 2) {
            if (q[i].empty()) break;

            int v = q[i].front();
            q[i].pop();

            x[i][j] = v;
            s[j].insert(v);
        }
    }

    rep(i, m) {
        int mx[2] = {};
        rep(j, a[i]) mx[j] = *s[j].rbegin();

        int ans;
        if (mx[0] > mx[1]) {
            ans = mx[0];
            int r = pos[ans];

            rep(j, 2) {
                if (x[r][j] > 0) s[j].erase(x[r][j]);
            }

            x[r][0] = x[r][1];
            x[r][1] = 0;
            if (!q[r].empty()) {
                int v = q[r].front();
                q[r].pop();
                x[r][1] = v;
            }

            rep(j, 2) {
                if (x[r][j] > 0) s[j].insert(x[r][j]);
            }

        } else {
            ans = mx[1];
            int r = pos[ans];

            s[1].erase(ans);
            x[r][1] = 0;
            if (!q[r].empty()) {
                int v = q[r].front();
                q[r].pop();
                x[r][1] = v;
            }
            s[1].insert(x[r][1]);
        }
        cout << ans << "\n";
    }

    return 0;
}
