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

const int INF = 19191;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(n, INF), b(n, INF);
    rep(i, n) if (s[i] == '#') a[i] = b[i] = 0;

    for (int i = n - 2; i >= 0; --i) a[i] = min(a[i], a[i + 1] + 1);
    for (int i = 1; i < n; ++i) b[i] = min(b[i], b[i - 1] + 1);

    int X = INF, Y = INF;
    rep(x, 50) rep(y, 50) {
        bool ok = true;
        rep(i, n) {
            if (a[i] <= x || b[i] <= y) continue;
            ok = false;
        }
        if (ok && x + y < X + Y) {
            X = x;
            Y = y;
        }
    }

    cout << X << " " << Y << "\n";
    return 0;
}
