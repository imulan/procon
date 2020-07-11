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

const int A = 26;

string solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];

    vector<int> ct(A);
    for (char c : s) ++ct[c - 'a'];

    string ans(m, '?');
    vector<bool> used(m);

    int ci = A - 1;
    while (1) {
        vector<int> v;
        rep(i, m) if (!used[i]) {
            int x = 0;
            rep(j, m) if (used[j]) x += abs(i - j);
            if (x == b[i]) v.pb(i);
        }

        if (v.empty()) break;

        int V = v.size();
        while (ct[ci] < V) --ci;

        for (int i : v) {
            used[i] = true;
            ans[i] = 'a' + ci;
        }
        --ci;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
