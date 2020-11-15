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

    vector<vector<int>> a(h);
    rep(i, h) {
        string s;
        cin >> s;
        vector<int> x(w);
        rep(j, w) x[j] = s[j] - '0';
        a[i] = x;
    }

    for (int n = min(h, w); n >= 1; --n) {
        rep(ly, h - n + 1) rep(lx, w - n + 1) {
            int ct[10] = {};
            rep(i, n) rep(j, n)++ ct[a[ly + i][lx + j]];

            int mx = 0;
            rep(i, 10) mx = max(mx, ct[i]);
            int need = n * n - mx;
            if (need <= k) {
                cout << n << "\n";
                return 0;
            }
        }
    }

    return 0;
}
