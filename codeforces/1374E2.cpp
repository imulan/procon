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

const ll INF = LLONG_MAX / 3;
using pi = pair<int, int>;

int main() {
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<pi> x[4];
    vector<int> T(n);
    rep(i, n) {
        int t, a, b;
        scanf(" %d %d %d", &t, &a, &b);
        x[(a << 1) | b].pb({t, i});
        T[i] = t;
    }
    rep(i, 4) sort(all(x[i]));

    int common = x[3].size();
    int alice = x[2].size(), bob = x[1].size();

    vector<ll> A(alice + 1), B(bob + 1);
    rep(i, alice) A[i + 1] = A[i] + x[2][i].fi;
    rep(i, bob) B[i + 1] = B[i] + x[1][i].fi;

    set<pi> X, SUB;
    ll sum_p = 0;
    int sz = 0;
    rep(i, 3) for (const auto& p : x[i]) {
        sum_p += p.fi;
        X.insert(p);
        ++sz;
    }

    auto REMOVE = [&](pi p) {
        if (X.count(p)) {
            sum_p -= p.fi;
            --sz;
            X.erase(p);
        } else {
            assert(SUB.count(p));
            SUB.erase(p);
        }
    };

    ll tc = 0;
    for (const auto& p : x[3]) tc += p.fi;

    ll ans = INF;
    int ai = 0, bi = 0;
    int ci = -1;

    for (int i = common; i >= 0; --i) {
        int r = max(0, k - i);
        int g = m - (i + r + r);
        if (g >= 0 && r <= alice && r <= bob) {
            while (ai <= r - 1) REMOVE(x[2][ai++]);
            while (bi <= r - 1) REMOVE(x[1][bi++]);

            while (g < sz) {
                pi p = *X.rbegin();
                X.erase(p);
                --sz;

                sum_p -= p.fi;
                SUB.insert(p);
            }
            while (!SUB.empty() && sz < g) {
                pi p = *SUB.begin();
                SUB.erase(p);

                sum_p += p.fi;
                X.insert(p);
                ++sz;
            }

            if (sz == g) {
                ll tmp = tc + A[r] + B[r] + sum_p;
                if (tmp < ans) {
                    ans = tmp;
                    ci = i;
                }
            }
        }

        if (i > 0) tc -= x[3][i - 1].fi;
    }

    if (ans == INF)
        printf("-1\n");
    else {
        printf("%lld\n", ans);

        vector<bool> used(n);
        rep(i, ci) used[x[3][i].se] = true;
        int r = max(0, k - ci);
        rep(i, r) {
            used[x[1][i].se] = true;
            used[x[2][i].se] = true;
        }

        vector<pi> vv;
        rep(i, n) if (!used[i]) vv.pb({T[i], i});
        sort(all(vv));

        int rem = m - ci - r - r;
        rep(i, rem) used[vv[i].se] = true;

        vector<int> book;
        rep(i, n) if (used[i]) book.pb(i);
        assert(book.size() == m);
        rep(i, m) printf("%d%c", book[i] + 1, " \n"[i == m - 1]);
    }
    return 0;
}
