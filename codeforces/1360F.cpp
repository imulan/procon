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

string solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep(i, n) cin >> a[i];

    rep(ci, 26) rep(pos, m) {
        string s = a[0];
        s[pos] = 'a' + ci;

        bool ok = true;
        rep(i, n) {
            int d = 0;
            rep(j, m) d += (s[j] != a[i][j]);

            if (d > 1) {
                ok = false;
                break;
            }
        }
        if (ok) return s;
    }

    return "-1";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) cout << solve() << "\n";
    return 0;
}
