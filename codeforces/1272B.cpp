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
    string s;
    cin >> s;

    map<char, int> ct;
    for (char c : s) ++ct[c];

    int x = min(ct['L'], ct['R']), y = min(ct['U'], ct['D']);

    string ans = "";
    if (x == 0) {
        if (y > 0) ans = "UD";
    } else if (y == 0) {
        if (x > 0) ans = "LR";
    } else {
        rep(i, x) ans += 'L';
        rep(i, y) ans += 'U';
        rep(i, x) ans += 'R';
        rep(i, y) ans += 'D';
    }

    cout << ans.size() << "\n";
    cout << ans << "\n";
}

int main() {
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}
