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

const int dy[2] = {1, 0};
const int dx[2] = {0, 1};

bool solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    auto IN = [&](int y, int x) { return 0 <= y && y < n && 0 <= x && x < n; };

    auto check = [&](int y, int x) {
        rep(i, 2) {
            int ny = y + dy[i], nx = x + dx[i];
            if (!IN(ny, nx) || s[ny][nx] == '1') return true;
        }
        return false;
    };

    rep(i, n) rep(j, n) if (s[i][j] == '1') {
        if (!check(i, j)) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
