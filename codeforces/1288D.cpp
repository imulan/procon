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
const pi NG(-1, -1);

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) scanf(" %d", &a[i][j]);

    const int M = 1 << m;
    auto F = [&](int x) {
        vector<int> idx(M, -1);
        rep(i, n) {
            int mask = 0;
            rep(j, m) {
                if (a[i][j] >= x) mask |= (1 << j);
            }
            idx[mask] = i;
        }

        rep(i, M) rep(j, M) {
            if (idx[i] == -1 || idx[j] == -1) continue;
            if ((i | j) == M - 1) return pi(idx[i], idx[j]);
        }
        return NG;
    };

    int ok = 0, ng = 1e9 + 1;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if (F(mid) == NG)
            ng = mid;
        else
            ok = mid;
    }

    pi ans = F(ok);
    printf("%d %d\n", ans.fi + 1, ans.se + 1);
    return 0;
}
