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

    vector<int> ct(3 * n);
    rep(i, n) {
        int w;
        cin >> w;
        ++ct[w];
    }

    int ans = 0;
    rep(s, 2 * n + 1) {
        int k = 0;
        rep(i, n + 1) {
            int j = s - i;
            if (j < i) break;

            if (j == i)
                k += ct[i] / 2;
            else
                k += min(ct[i], ct[j]);
        }
        ans = max(ans, k);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
