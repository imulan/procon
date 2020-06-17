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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n * a != m * b) {
        cout << "NO\n";
        return;
    }

    vector<string> s(n, string(m, '0'));
    int idx = 0;
    rep(i, n) {
        rep(j, a) {
            s[i][idx] = '1';
            idx = (idx + 1) % m;
        }
    }

    cout << "YES\n";
    rep(i, n) cout << s[i] << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}
