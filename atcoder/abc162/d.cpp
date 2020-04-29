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
    string s;
    cin >> n >> s;

    vector<int> v(n);
    rep(i, n) {
        if (s[i] == 'R')
            v[i] = 0;
        else if (s[i] == 'G')
            v[i] = 1;
        else
            v[i] = 2;
    }

    vector<vector<int>> pre(3, vector<int>(n));
    rep(i, n) pre[v[i]][i] = 1;
    rep(i, 3) rep(j, n - 1) pre[i][j + 1] += pre[i][j];

    ll ans = 0;
    rep(i, n) for (int j = i + 1; j < n; ++j) {
        if (v[i] == v[j]) continue;
        int idx = 3 - v[i] - v[j];

        int d = j - i;
        int ng_k = j + d;

        int add = pre[idx][n - 1] - pre[idx][j];
        if (ng_k < n && v[ng_k] == idx) --add;

        ans += add;
    }
    cout << ans << "\n";
    return 0;
}
