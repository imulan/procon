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

string solve() {
    int n;
    ll k;
    cin >> n >> k;
    --k;

    int x[2];
    x[0] = n - 2;
    x[1] = n - 1;

    for (int i = 1; i < n; ++i) {
        if (k - i >= 0) {
            --x[0];
            k -= i;
        }
    }

    while (k) {
        --k;
        --x[1];
    }

    string ans(n, 'a');
    rep(i, 2) ans[x[i]] = 'b';
    return ans;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) cout << solve() << "\n";
    return 0;
}
