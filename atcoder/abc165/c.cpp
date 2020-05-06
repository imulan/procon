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

const int N = 55;

int n, m, q;
int a[N], b[N], c[N], d[N];

int ans = 0;
int x[N];

void dfs(int k, int p) {
    if (k == n) {
        int t = 0;
        rep(i, q) {
            if (x[b[i]] - x[a[i]] == c[i]) t += d[i];
        }
        ans = max(ans, t);
        return;
    }

    for (int i = p; i <= m; ++i) {
        x[k] = i;
        dfs(k + 1, i);
    }
}

int main() {
    cin >> n >> m >> q;
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
    }

    dfs(0, 1);
    cout << ans << "\n";
    return 0;
}
