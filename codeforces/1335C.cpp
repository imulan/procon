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

int solve() {
    int n;
    cin >> n;

    map<int, int> ct;
    rep(i, n) {
        int a;
        cin >> a;
        ++ct[a];
    }

    int d = ct.size();
    int ans = 0;
    for (const auto& p : ct) {
        ans = max(ans, min(d, p.se - 1));
        ans = max(ans, min(d - 1, p.se));
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
