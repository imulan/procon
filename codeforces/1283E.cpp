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

const int N = 200002;
const int INF = 19191919;
int mn[N][3], mx[N][3];

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    sort(all(x));

    rep(i, N) rep(j, 3) {
        mn[i][j] = INF;
        mx[i][j] = -INF;
    }

    rep(i, 3) mn[0][i] = mx[0][i] = 1;

    for (int i = 1; i < n; ++i) rep(j, 3) {
            int pos = x[i] + j - 1;
            rep(k, 3) {
                int pre = x[i - 1] + k - 1;
                if (pos < pre) continue;

                int add = (pos != pre);
                mn[i][j] = min(mn[i][j], mn[i - 1][k] + add);
                mx[i][j] = max(mx[i][j], mx[i - 1][k] + add);
            }
        }

    int a = INF, b = -INF;
    rep(i, 3) {
        a = min(a, mn[n - 1][i]);
        b = max(b, mx[n - 1][i]);
    }
    cout << a << " " << b << "\n";
    return 0;
}
