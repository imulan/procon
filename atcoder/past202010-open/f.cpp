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
    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    map<string, int> m;
    rep(i, n) {
        cin >> s[i];
        ++m[s[i]];
    }

    vector<int> ct;
    for (const auto& p : m) ct.pb(p.se);
    sort(all(ct), greater<int>());

    int tgt = ct[k - 1];
    int uniq = 0;
    for (int i : ct)
        if (i == tgt) ++uniq;

    string ans = "AMBIGUOUS";
    if (uniq == 1) {
        for (const auto& p : m)
            if (p.se == tgt) ans = p.fi;
    }
    cout << ans << "\n";
    return 0;
}
