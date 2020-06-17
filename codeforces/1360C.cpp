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

    vector<int> v[2];
    rep(i, n) {
        int a;
        cin >> a;
        v[a % 2].pb(a);
    }

    int sz[2];
    rep(i, 2) sz[i] = v[i].size();

    if (sz[0] % 2 == 0) return true;

    for (int i : v[0])
        for (int j : v[1]) {
            if (abs(i - j) == 1) return true;
        }
    return false;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}
