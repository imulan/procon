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

using vi = vector<int>;

int main() {
    int n, k;
    char s[3003];
    scanf(" %d %d", &n, &k);
    scanf(" %s", s);

    vi v(n);
    rep(i, n) v[i] = (s[i] == 'R');

    vi inv;
    rep(i, n - 1) {
        if (v[i] == 1 && v[i + 1] == 0) inv.pb(i);
    }

    auto f = [&]() {
        unordered_set<int> ch;

        vi ret;
        for (int i : inv) {
            ret.pb(i);
            swap(v[i], v[i + 1]);
            for (int j = -1; j <= 1; ++j) {
                int l = i + j, r = i + j + 1;
                if (0 <= l && r < n) ch.insert(l);
            }
        }

        inv.clear();
        for (int i : ch) {
            if (v[i] == 1 && v[i + 1] == 0) inv.pb(i);
        }
        return ret;
    };

    int mn = 0, mx = 0;
    vector<vi> a;
    while (1) {
        vi t = f();
        if (t.empty()) break;

        ++mn;
        mx += t.size();
        a.pb(t);
    }
    // dbg(a);

    if (mn <= k && k <= mx) {
        int now = mn;
        int ai = 0, aj = 0;

        vector<vi> ans;
        while (now < k) {
            ans.pb(vi({a[ai][aj]}));

            ++now;
            ++aj;
            if (aj == a[ai].size()) {
                ++ai;
                aj = 0;
                --now;
            }
            // printf("%d %d %d\n", ai, aj, now);
        }

        if (aj != 0) {
            vi rem;
            for (int i = aj; i < a[ai].size(); ++i) rem.pb(a[ai][i]);
            ans.pb(rem);
            ++ai;
            aj = 0;
        }
        for (int i = ai; i < a.size(); ++i) ans.pb(a[i]);

        for (const auto& p : ans) {
            printf("%d", p.size());
            for (int i : p) printf(" %d", i + 1);
            printf("\n");
        }
    } else
        printf("-1\n");

    return 0;
}
