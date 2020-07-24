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

void solve() {
    int n;
    scanf(" %d", &n);

    vector<bool> used(n + 1);
    vector<int> p;
    rep(i, 2 * n) {
        int a;
        scanf(" %d", &a);
        if (!used[a]) {
            used[a] = true;
            p.pb(a);
        }
    }
    rep(i, n) printf("%d%c", p[i], " \n"[i == n - 1]);
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) solve();
    return 0;
}
