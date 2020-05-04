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
    int n;
    cin >> n;

    vector<pi> p(1 << n);
    rep(i, 1 << n) {
        cin >> p[i].fi;
        p[i].se = i;
    }

    vector<int> ans(1 << n, n);
    rep(i, n) {
        vector<pi> nx;

        int P = p.size();
        for (int j = 0; j < P; j += 2) {
            pi x = p[j], y = p[j + 1];
            if (x.fi > y.fi) swap(x, y);

            ans[x.se] = i + 1;
            nx.pb(y);
        }

        p = nx;
    }

    for (int i : ans) cout << i << "\n";
    return 0;
}
