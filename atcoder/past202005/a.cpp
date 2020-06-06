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
    string s, t;
    cin >> s >> t;
    string ans = "different";

    if (s == t)
        ans = "same";
    else {
        rep(i, s.size()) s[i] = tolower(s[i]);
        rep(i, t.size()) t[i] = tolower(t[i]);
        if (s == t) ans = "case-insensitive";
    }
    cout << ans << "\n";
    return 0;
}
