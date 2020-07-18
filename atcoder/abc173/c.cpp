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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int ans = 0;
    rep(hmask, 1 << h) rep(wmask, 1 << w) {
        vector<string> t(s);
        rep(i, h) if (hmask >> i & 1) { rep(j, w) t[i][j] = 'R'; }
        rep(i, w) if (wmask >> i & 1) { rep(j, h) t[j][i] = 'R'; }

        int ct = 0;
        rep(i, h) rep(j, w) ct += (t[i][j] == '#');
        ans += (ct == k);
    }
    cout << ans << "\n";
    return 0;
}
