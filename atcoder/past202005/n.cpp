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

using pi = pair<int, int>;

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);

    vector<int> a(n);
    rep(i, n) a[i] = i;

    set<int> inv;

    auto SWAP = [&](int x) {
        swap(a[x], a[x + 1]);
        for (int i = -1; i <= 1; ++i) {
            if (x + i < 0 || n <= x + 1 + i) continue;
            if (a[x + i] > a[x + i + 1])
                inv.insert(x + i);
            else
                inv.erase(x + i);
        }
    };

    rep(query, q) {
        int t, x, y;
        scanf(" %d %d %d", &t, &x, &y);
        --x;
        --y;
        if (t == 1) {
            SWAP(x);
        } else {
            while (1) {
                auto itr = inv.lower_bound(x);
                if (itr == inv.end() || *itr >= y) break;
                SWAP(*itr);
            }
        }

        //  dbg((vector<int>(all(inv))));
        // rep(i, n) printf("%d%c", a[i] + 1, " \n"[i == n - 1]);
    }

    rep(i, n) printf("%d%c", a[i] + 1, " \n"[i == n - 1]);
    return 0;
}
