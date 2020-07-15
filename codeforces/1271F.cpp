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
    int A[2], B[2], C[2], d[7];
    rep(i, 2) scanf(" %d %d %d", &A[i], &B[i], &C[i]);
    rep(i, 7) scanf(" %d", &d[i]);

    int a[2], b[2], c[2], x[2][7];
    rep(ii, d[1] + 1) rep(jj, d[2] + 1) rep(kk, d[4] + 1) {
        rep(i, 2) {
            a[i] = A[i];
            b[i] = B[i];
            c[i] = C[i];
        }

        x[0][1] = ii;
        x[1][1] = d[1] - ii;
        x[0][2] = jj;
        x[1][2] = d[2] - jj;
        x[0][4] = kk;
        x[1][4] = d[4] - kk;

        bool ok = true;
        rep(i, 2) {
            a[i] -= x[i][1] + x[i][2];
            b[i] -= x[i][1] + x[i][4];
            c[i] -= x[i][2] + x[i][4];
            if (a[i] < 0 || b[i] < 0 || c[i] < 0) ok = false;
        }
        if (!ok) continue;

        x[0][0] = min({a[0], b[0], c[0], d[0]});
        x[1][0] = d[0] - x[0][0];
        rep(i, 2) {
            a[i] -= x[i][0];
            b[i] -= x[i][0];
            c[i] -= x[i][0];
            if (a[i] < 0 || b[i] < 0 || c[i] < 0) ok = false;
        }
        if (!ok) continue;

        x[0][3] = min(a[0], d[3]);
        x[1][3] = d[3] - x[0][3];
        x[0][5] = min(b[0], d[5]);
        x[1][5] = d[5] - x[0][5];
        x[0][6] = min(c[0], d[6]);
        x[1][6] = d[6] - x[0][6];
        rep(i, 2) {
            a[i] -= x[i][3];
            b[i] -= x[i][5];
            c[i] -= x[i][6];
            if (a[i] < 0 || b[i] < 0 || c[i] < 0) ok = false;
        }

        if (ok) {
            rep(i, 7) printf("%d%c", x[0][i], " \n"[i == 6]);
            return;
        }
    }
    printf("-1\n");
    return;
}
int main() {
    int t;
    scanf(" %d", &t);
    while (t--) solve();
    return 0;
}
