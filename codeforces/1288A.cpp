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

bool solve() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i * i <= d; ++i) {
        int q = i + 1;
        int t = i + (d + q - 1) / q;
        if (t <= n) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
