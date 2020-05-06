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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v;

    int s = 1;
    for (int i = m; i > 0; i -= 2) {
        v.pb({s, s + i});
        ++s;
    }

    s = m + 2;
    for (int i = m - 1; i > 0; i -= 2) {
        v.pb({s, s + i});
        ++s;
    }

    for (auto& p : v) cout << p.fi << " " << p.se << "\n";
    return 0;
}
