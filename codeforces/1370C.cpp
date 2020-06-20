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

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool solve() {
    int n;
    cin >> n;

    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 1) return true;

    int x = 1;
    while (x < n) {
        x *= 2;
        if (n == x) return false;
    }

    int h = n / 2;
    if (isPrime(h)) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) cout << (solve() ? "Ashishgup" : "FastestFinger") << "\n";
    return 0;
}
