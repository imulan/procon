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

    vector<vector<bool>> solve(n, vector<bool>(m));
    vector<int> score(m, n);

    rep(query, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;

            int ans = 0;
            rep(i, m) {
                if (solve[x][i]) ans += score[i];
            }
            cout << ans << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            --score[y];
            solve[x][y] = true;
        }
    }

    return 0;
}
