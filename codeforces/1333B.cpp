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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    map<int, int> ct;
    rep(i, n) ct[a[i]]++;

    for (int i = n - 1; i >= 0; --i) {
        ct[a[i]]--;
        if (a[i] == b[i]) continue;

        if (a[i] > b[i]) {
            if (ct[-1] == 0) return false;
        } else {
            if (ct[1] == 0) return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
