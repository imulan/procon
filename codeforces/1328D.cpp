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
    vector<int> t(n);
    rep(i, n) scanf(" %d", &t[i]);

    set<int> s;
    for (int i : t) s.insert(i);

    int k = 0;
    vector<int> c(n);
    if (s.size() == 1) {
        k = 1;
        rep(i, n) c[i] = 0;
    } else {
        if (n % 2 == 0) {
            k = 2;
            rep(i, n) c[i] = i % 2;
        } else {
            int idx = -1;
            rep(i, n) {
                int ni = (i + 1) % n;
                if (t[i] == t[ni]) idx = i;
            }

            if (idx == -1) {
                k = 3;
                c[0] = 2;
                for (int i = 1; i < n; ++i) c[i] = i % 2;
            } else {
                k = 2;
                c[idx] = c[(idx + 1) % n] = 1;
                for (int i = 2; i < n; ++i) {
                    int ni = (idx + i) % n;
                    c[ni] = i % 2;
                }
            }
        }
    }

    printf("%d\n", k);
    rep(i, n) printf("%d%c", c[i] + 1, " \n"[i == n - 1]);
}

int main() {
    int T;
    scanf(" %d", &T);
    rep(i, T) solve();
    return 0;
}
