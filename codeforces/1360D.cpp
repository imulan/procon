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
    int n, k;
    scanf(" %d %d", &n, &k);

    int ret = n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            for (int j : {i, n / i})
                if (j <= k) ret = min(ret, n / j);
        }
    }
    return ret;
}

int main() {
    int t;
    scanf(" %d", &t);
    rep(i, t) printf("%d\n", solve());
    return 0;
}
