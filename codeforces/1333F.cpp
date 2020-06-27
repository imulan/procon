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

const int N = 500005;
int p[N];

int main() {
    rep(i, N) p[i] = i;
    for (int i = 2; i < N; ++i) {
        if (p[i] == i) {
            for (int j = 2 * i; j < N; j += i) p[j] = min(p[j], i);
        }
    }

    int n;
    scanf(" %d", &n);

    vector<int> y(n + 1);
    for (int i = 1; i <= n; ++i) ++y[i / p[i]];

    int ct = 0;
    vector<int> ans(n + 1, n);

    for (int i = 1; i <= n; ++i) {
        ct += y[i];
        ans[ct] = min(ans[ct], i);
    }

    for (int i = n - 1; i > 0; --i) ans[i] = min(ans[i], ans[i + 1]);

    for (int i = 2; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}
