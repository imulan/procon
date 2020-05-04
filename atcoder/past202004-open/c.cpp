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
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    const int W = 2 * n - 1;

    for (int i = n - 2; i >= 0; --i) {
        rep(j, W) if (s[i][j] == '#') {
            for (int k = -1; k <= 1; ++k) {
                int nj = j + k;
                if (nj < 0 || W <= nj) continue;
                if (s[i + 1][nj] == 'X') s[i][j] = 'X';
            }
        }
    }

    rep(i, n) cout << s[i] << "\n";
    return 0;
}
