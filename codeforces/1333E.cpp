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

int x[3][3] = {{8, 4, 5}, {6, 1, 7}, {0, 2, 3}};

int main() {
    int n;
    scanf(" %d", &n);

    if (n <= 2) {
        printf("-1\n");
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(n));
    int now = 0;
    for (int i = n - 1; i > 2; --i) {
        if ((i - 2) % 2 == 1) {
            // upper right to lower left
            rep(j, i) a[j][i] = now++;
            a[i][i] = now++;
            for (int j = i - 1; j >= 0; --j) a[i][j] = now++;
        } else {
            // lower left to upper right
            rep(j, i) a[i][j] = now++;
            a[i][i] = now++;
            for (int j = i - 1; j >= 0; --j) a[j][i] = now++;
        }
    }

    rep(i, 3) rep(j, 3) a[i][j] = now + x[i][j];

    rep(i, n) rep(j, n) printf("%d%c", a[i][j] + 1, " \n"[j == n - 1]);
    return 0;
}
