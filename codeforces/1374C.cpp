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

int solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> L, R;
    rep(i, n) {
        if (s[i] == '(')
            L.pb(i);
        else
            R.pb(i);
    }
    reverse(all(L));

    rep(mv, n) {
        rep(l, mv + 1) {
            int r = mv - l;
            vector<bool> x(n, true);
            rep(i, l) x[L[i]] = false;
            rep(i, r) x[R[i]] = false;

            bool ok = true;
            int d = l;
            rep(i, n) if (x[i]) {
                if (s[i] == '(')
                    ++d;
                else
                    --d;
                if (d < 0) ok = false;
            }
            if (ok) return mv;
        }
    }
    assert(false);
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
