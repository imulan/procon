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

const int N = 100010;
vector<int> p[N], x[N], pre[N];
int sm[N];

int main() {
    int d, l, n;
    scanf(" %d %d %d", &d, &l, &n);

    rep(i, d) {
        int c;
        scanf(" %d", &c);
        p[c].pb(i);
    }

    rep(i, N) if (!p[i].empty()) {
        int sz = p[i].size();
        rep(j, sz) p[i].pb(p[i][j] + d);

        sm[i] = sz;
        x[i] = vector<int>(sz);
        rep(j, sz) {
            int w = p[i][j + 1] - p[i][j];
            x[i][j] = (w - 1) / l;
            sm[i] += x[i][j];
        }

        pre[i] = vector<int>(2 * sz);
        rep(j, sz) pre[i][j] = pre[i][sz + j] = x[i][j];
        rep(j, 2 * sz - 1) pre[i][j + 1] += pre[i][j];
    }

    auto calc_pre = [&](int k, int idx) {
        if (idx < 0) return 0;
        return pre[k][idx];
    };

    auto solve = [&](int k, int f, int t) {
        if (p[k].empty()) return 0;

        int f_idx = lower_bound(all(p[k]), f) - p[k].begin();
        t -= (p[k][f_idx] - f + l - 1) / l;
        if (t <= 0) return 0;

        int sz = p[k].size();
        sz /= 2;
        f_idx %= sz;

        int loop = t / sm[k];
        int ret = loop * sz;

        t -= loop * sm[k];

        int ok = 0, ng = sz + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;

            int sx = calc_pre(k, f_idx + mid - 2) - calc_pre(k, f_idx - 1);
            int ct = mid + sx;
            if (ct <= t)
                ok = mid;
            else
                ng = mid;
        }
        ret += ok;

        return ret;
    };

    rep(i, n) {
        int k, f, t;
        scanf(" %d %d %d", &k, &f, &t);
        --f;
        printf("%d\n", solve(k, f, t));
    }
    return 0;
}
