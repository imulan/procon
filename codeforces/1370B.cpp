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

void solve() {
    int n;
    scanf(" %d", &n);

    int A = 2 * n;
    vector<int> v[2];
    rep(i, A) {
        int a;
        scanf(" %d", &a);
        v[a % 2].pb(i);
    }

    int sz[2];
    rep(i, 2) sz[i] = v[i].size();

    if (sz[0] % 2 == 1) {
        --sz[0];
        --sz[1];
    } else {
        if (sz[0] > 0)
            sz[0] -= 2;
        else
            sz[1] -= 2;
    }

    rep(i, 2) {
        for (int j = 0; j + 1 < sz[i]; j += 2) {
            printf("%d %d\n", v[i][j] + 1, v[i][j + 1] + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}
