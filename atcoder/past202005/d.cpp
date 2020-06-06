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
    string s[5];

    cin >> n;
    rep(i, 5) cin >> s[i];

    rep(i, n) {
        int l = 4 * i;

        int ct = 0;
        rep(y, 5) rep(x, 4) {
            if (s[y][l + x] == '#') ++ct;
        }

        int ans = 8;
        if (ct == 7)
            ans = 7;
        else if (ct == 8)
            ans = 1;
        else if (ct == 9)
            ans = 4;
        else if (ct == 11) {
            // 2,3,5
            if (s[1][l + 1] == '#')
                ans = 5;
            else if (s[3][l + 1] == '#')
                ans = 2;
            else
                ans = 3;
        } else if (ct == 12) {
            // 0,6,9
            if (s[1][l + 3] == '.')
                ans = 6;
            else if (s[3][l + 1] == '.')
                ans = 9;
            else
                ans = 0;
        }

        cout << ans;
    }
    cout << "\n";
    return 0;
}
