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

const int N = 9;

void solve() {
    vector<string> s(N);
    rep(i, N) cin >> s[i];

    rep(i, N) {
        int one = 0;
        rep(j, N) if (s[i][j] == '1') one = j;

        int pos = one + 1;
        if (one % 3 == 2) pos = one - 2;
        s[i][pos] = '1';
    }

    rep(i, N) cout << s[i] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
