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

int main() {
    int n;
    cin >> n;

    vector<int> f(n), x;
    vector<bool> used(n);
    rep(i, n) {
        cin >> f[i];
        --f[i];
        if (f[i] == -1)
            x.pb(i);
        else
            used[f[i]] = true;
    }

    vector<int> y;
    for (int i : x)
        if (!used[i]) y.pb(i);

    int Y = y.size();
    if (Y >= 2) {
        rep(i, Y) f[y[i]] = y[(i + 1) % Y];
        for (int i : y) used[i] = true;
    } else if (Y == 1) {
        rep(i, n) {
            if (!used[i] && i != y[0]) {
                used[i] = true;
                f[y[0]] = i;
                break;
            }
        }
    }

    int idx = 0;
    rep(i, n) if (f[i] == -1) {
        while (idx < n && used[idx]) ++idx;
        f[i] = idx;
        used[idx] = true;
    }

    rep(i, n) cout << f[i] + 1 << " \n"[i == n - 1];
    return 0;
}
