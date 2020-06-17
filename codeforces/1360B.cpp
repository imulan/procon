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
    scanf(" %d", &n);
    vector<int> s(n);
    rep(i, n) scanf(" %d", &s[i]);
    sort(all(s));

    int ans = 191919;
    rep(i, n - 1) ans = min(ans, s[i + 1] - s[i]);
    return ans;
}

int main() {
    int T;
    scanf(" %d", &T);
    rep(i, T) printf("%d\n", solve());
    return 0;
}
