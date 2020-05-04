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

const int N = 100010;
const string ABC = "ABC";

int n, v[3];
string s[N];

bool ok = false;
char ans[N];

set<vector<int>> vis[N];
void dfs(int d, vector<int> x) {
    if (d == n) {
        ok = true;
        return;
    }
    if (vis[d].count(x)) return;
    vis[d].insert(x);

    bool b[3] = {};
    int z = 0;
    for (char c : s[d]) {
        b[c - 'A'] = true;
        z += c - 'A';
    }
    rep(i, 3) if (b[i]) {
        vector<int> nx(x);
        ++nx[i];
        --nx[z - i];

        bool valid = true;
        rep(j, 3) if (abs(nx[j]) > 2 || v[j] + nx[j] < 0) valid = false;

        if (valid) {
            ans[d] = ABC[i];
            dfs(d + 1, nx);
        }
        if (ok) return;
    }
}

int main() {
    cin >> n;
    rep(i, 3) cin >> v[i];
    rep(i, n) cin >> s[i];

    dfs(0, vector<int>(3, 0));

    if (!ok) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    rep(i, n) cout << ans[i] << "\n";
    return 0;
}
