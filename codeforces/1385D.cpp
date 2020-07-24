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

int n;
string s;

int dfs(int l, int r, char c) {
    int w = r - l + 1;
    if (w == 1) {
        return s[l] != c;
    }

    int ret = n;

    int t = 0;
    int idx = l;
    rep(i, w / 2) {
        t += (s[idx] != c);
        ++idx;
    }
    ret = min(ret, dfs(l + w / 2, r, c + 1) + t);

    t = 0;
    idx = r;
    rep(i, w / 2) {
        t += (s[idx] != c);
        --idx;
    }
    ret = min(ret, dfs(l, r - w / 2, c + 1) + t);
    return ret;
}

int solve() {
    cin >> n >> s;
    return dfs(0, n - 1, 'a');
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
