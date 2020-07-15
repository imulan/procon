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
    vector<int> v(4);
    rep(i, 4) cin >> v[i];
    ll e, f;
    cin >> e >> f;

    ll ans = 0;
    rep(i, min(v[0], v[3]) + 1) {
        int j = min({v[1], v[2], v[3] - i});
        ans = max(ans, e * i + f * j);
    }
    cout << ans << "\n";
    return 0;
}
