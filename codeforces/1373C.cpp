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

ll solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> v(n);
    int t = 0, mn = 0;
    rep(i, n) {
        if (s[i] == '+')
            ++t;
        else
            --t;
        v[i] = t;
        mn = min(mn, v[i]);
    }

    map<int, int> most_left;
    for (int i = n - 1; i >= 0; --i) most_left[v[i]] = i;

    ll ans = n;
    for (int i = -1; i >= mn; --i) ans += most_left[i] + 1;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
