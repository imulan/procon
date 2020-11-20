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

void solve() {
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i, n) scanf(" %d", &a[i]);

    int inv = 0;
    rep(i, n) rep(j, i) inv += (a[j] > a[i]);

    vector<pi> v(n);
    rep(i, n) v[i] = {a[i], i};
    sort(all(v));

    rep(i, n - 1) {
        if (v[i].fi == v[i + 1].fi && inv % 2 == 1) {
            swap(v[i], v[i + 1]);
            ++inv;
            break;
        }
    }
    if (inv % 2 == 1) {
        printf("-1\n");
        return;
    }

    vector<int> x(n);
    rep(i, n) x[v[i].se] = i;

    vector<int> op;
    auto F = [&](int idx) {
        op.pb(idx);

        vector<int> tmp;
        rep(i, 3) tmp.pb(x[idx + i]);

        x[idx] = tmp[2];
        x[idx + 1] = tmp[0];
        x[idx + 2] = tmp[1];
    };

    rep(i, n - 2) {
        int now = 0;
        while (x[now] != i) ++now;

        while (i < now) {
            if (now - 2 >= i)
                F(now - 2);
            else
                F(i);

            for (int j = -2; j <= 2; ++j) {
                int t = now + j;
                if (0 <= t && t < n && x[t] == i) now = t;
            }

            // printf(" i:%d  now %d ", i, now);
            // dbg(x);
        }
    }

    int sz = op.size();
    printf("%d\n", sz);
    rep(i, sz) {
        if (i > 0) printf(" ");
        printf("%d", op[i] + 1);
    }
    printf("\n");
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) solve();
    return 0;
}
