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
    int n;
    string s;
    cin >> n >> s;

    // a <= b
    string a(n, '?'), b(n, '?');
    bool one = false;
    rep(i, n) {
        int v = s[i] - '0';

        if (v == 1) {
            if (one) {
                a[i] = '1';
                b[i] = '0';
            } else {
                a[i] = '0';
                b[i] = '1';
            }

            one = true;
        } else {
            if (one) {
                a[i] = '0' + v;
                b[i] = '0';
            } else {
                a[i] = b[i] = '0' + v / 2;
            }
        }
    }

    for (auto& i : {a, b}) cout << i << "\n";
}

int main() {
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}
