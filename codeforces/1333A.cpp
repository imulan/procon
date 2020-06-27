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
    int h, w;
    cin >> h >> w;
    vector<string> s(h, string(w, 'W'));

    rep(i, h) rep(j, w) {
        if ((i + j) % 2 == 0) s[i][j] = 'B';
    }

    if (h % 2 == 0 && w % 2 == 0)
        s[0][w - 1] = 'B';
    else if (h % 2 == 0 || w % 2 == 0)
        s[h - 1][w - 1] = 'B';

    rep(i, h) cout << s[i] << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}
