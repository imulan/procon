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

struct table {
    int bottom, top;
};

struct container {
    int l, r;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<table> t(n);
    vector<container> c(2 * n);

    auto pos = [&]() {
        vector<int> ans(n);
        rep(i, n) {
            int x = t[i].bottom;
            x = c[x].r;

            // printf(" %d: ", i);
            while (x != -1) {
                // printf(" %d", x);
                ans[x] = i;
                x = c[x].r;
            }
            // printf("\n");
        }
        return ans;
    };

    rep(i, n) {
        t[i] = {n + i, i};
        c[n + i] = {-1, i};
        c[i] = {n + i, -1};
    }

    rep(i, q) {
        int from, to, x;
        cin >> from >> to >> x;
        --from;
        --to;
        --x;

        int u = t[to].top;

        int new_from_top = c[x].l;
        c[u].r = x;
        c[x].l = u;
        c[new_from_top].r = -1;

        t[to].top = t[from].top;
        t[from].top = new_from_top;

        // vector<int> cc = pos();
        // dbg(cc);
    }

    vector<int> ans = pos();
    for (int i : ans) cout << i + 1 << "\n";
    return 0;
}
