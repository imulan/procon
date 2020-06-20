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

const int N = 1000010;

int one(const string& s) {
    int ct = 0;
    for (char c : s)
        if (c == '1') ++ct;
    return ct;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s, t;
    cin >> n >> s >> t;

    if (one(s) != one(t)) {
        cout << -1 << "\n";
        return 0;
    }

    set<int> d[2];
    rep(i, n) {
        if (s[i] == '0' && t[i] == '1') {
            d[0].insert(i);
        }
        if (s[i] == '1' && t[i] == '0') {
            d[1].insert(i);
        }
    }
    rep(i, 2) d[i].insert(n);

    int ans = 0;
    while (1) {
        bool empty = true;
        rep(i, 2) if (*(d[i].begin()) != n) empty = false;
        if (empty) break;

        int idx = 0;
        if (*(d[0].begin()) > *(d[1].begin())) idx = 1;

        int pos = 0;
        while (1) {
            auto itr = d[idx].lower_bound(pos);
            pos = *itr;
            if (pos == n) break;
            d[idx].erase(itr);
            idx = !idx;
        }
        ++ans;
    }

    cout << ans << "\n";
    return 0;
}
