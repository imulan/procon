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
    string s;
    cin >> n >> s;

    vector<bool> v(n);
    rep(i, n) v[i] = (s[i] == 'W');

    rep(f, 2) {
        vector<bool> t(v);
        vector<int> p;
        auto FLIP = [&](int idx) {
            rep(i, 2) t[idx + i] = !t[idx + i];
            p.pb(idx);
        };

        if (f) FLIP(0);

        for (int i = 1; i + 1 < n; ++i) {
            if (t[0] != t[i]) FLIP(i);
        }

        bool ok = true;
        rep(i, n) if (t[0] != t[i]) ok = false;
        if (ok) {
            int P = p.size();
            cout << P << "\n";
            rep(i, P) cout << p[i] + 1 << " \n"[i == P - 1];
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
