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

const int N = 202;

int solve() {
    int n;
    scanf(" %d", &n);

    vector<vector<int>> pos(N);
    rep(i, n) {
        int a;
        scanf(" %d", &a);
        pos[a].pb(i);
    }

    int ans = 0;
    rep(a, N) {
        int A = pos[a].size();
        ans = max(ans, A);
        rep(b, N) {
            if (pos[b].empty()) continue;
            int B = pos[b].size();
            int lb = 0, rb = B - 1;

            for (int i = 1; 2 * i <= A; ++i) {
                int l = pos[a][i - 1], r = pos[a][A - i];
                while (lb < B && pos[b][lb] <= l) ++lb;
                while (rb >= 0 && r <= pos[b][rb]) --rb;

                int y = max(0, rb - lb + 1);
                ans = max(ans, 2 * i + y);
            }
        }
    }
    return ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%d\n", solve());
    return 0;
}
