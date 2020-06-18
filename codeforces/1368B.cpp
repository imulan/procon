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

const int X = 10;
string x = "codeforces";

int main() {
    ll k;
    cin >> k;

    vector<int> p(X, 1);

    int idx = 0;
    ll now = 1;
    while (now < k) {
        now /= p[idx];
        ++p[idx];
        now *= p[idx];
        (idx += 1) %= X;
    }

    rep(i, X) rep(j, p[i]) cout << x[i];
    cout << "\n";
    return 0;
}
