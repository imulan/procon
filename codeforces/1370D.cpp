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
    int n, k;
    scanf(" %d %d", &n, &k);
    vector<int> a(n);
    rep(i, n) scanf(" %d", &a[i]);

    vector<int> u(a);
    sort(all(u));
    u.erase(unique(all(u)), u.end());
    int U = u.size();

    auto check = [&](int idx) {
        int v = u[idx];

        vector<bool> small(n);
        rep(i, n) small[i] = (a[i] <= v);

        rep(f, 2) {
            int ct = 0;
            rep(i, n) {
                if (ct % 2 == f) {
                    if (small[i]) ++ct;
                } else
                    ++ct;
            }

            if (ct >= k) return true;
        }
        return false;
    };

    int ng = -1, ok = U - 1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    printf("%d\n", u[ok]);
    return 0;
}
