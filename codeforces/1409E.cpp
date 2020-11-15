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
    vector<int> x(n), y(n);
    rep(i, n) scanf(" %d", &x[i]);
    rep(i, n) scanf(" %d", &y[i]);

    vector<int> ux(x);
    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    int X = ux.size();

    vector<int> ct(X);
    rep(i, n) {
        int idx = lower_bound(all(ux), x[i]) - ux.begin();
        ++ct[idx];
    }

    vector<int> save(X);
    multiset<int> s({0});
    int now = 0, r = 0;
    rep(i, X) {
        while (r < X && ux[i] + k >= ux[r]) now += ct[r++];
        save[i] = now;
        now -= ct[i];
        s.insert(save[i]);
    }

    int ans = 0;
    r = 0;
    rep(i, X) {
        while (r < X && ux[i] + k >= ux[r]) s.erase(s.find(save[r++]));
        ans = max(ans, save[i] + *s.rbegin());
    }
    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%d\n", solve());
    return 0;
}
