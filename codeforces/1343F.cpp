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

const vector<int> NG(1, -1);

vector<int> solve() {
    int n;
    cin >> n;

    vector<set<int>> vs(n - 1);
    rep(i, n - 1) {
        int k;
        cin >> k;

        while (k--) {
            int x;
            cin >> x;
            vs[i].insert(x - 1);
        }
    }
    set<set<int>> range_set;
    rep(i, n - 1) range_set.insert(vs[i]);

    auto check = [&](int first_element) {
        vector<int> p(n);
        p[0] = first_element;

        vector<set<int>> x = vs;
        for (int i = 1; i < n; ++i) {
            int val = p[i - 1];
            vector<int> cand;
            rep(j, n - 1) {
                if (x[j].count(val)) x[j].erase(val);
                if (x[j].size() == 1) cand.pb(j);
            }
            if (cand.size() != 1) return NG;

            int vi = cand.front();
            p[i] = *x[vi].begin();
        }

        for (int i = 1; i < n; ++i) {
            set<int> t;
            bool found = false;
            for (int j = i; j >= 0; --j) {
                t.insert(p[j]);
                if (range_set.count(t)) {
                    found = true;
                    break;
                }
            }

            if (!found) return NG;
        }
        return p;
    };

    rep(i, n) {
        vector<int> v = check(i);
        if (v != NG) return v;
    }
    assert(false);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> ans = solve();
        int n = ans.size();
        rep(i, n) cout << ans[i] + 1 << " \n"[i == n - 1];
    }
    return 0;
}
