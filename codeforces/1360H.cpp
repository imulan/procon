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

ll f(string s) {
    int m = s.size();
    ll ret = 0;
    rep(i, m) {
        ret *= 2;
        if (s[i] == '1') ++ret;
    }
    return ret;
}

string solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) {
        string s;
        cin >> s;
        a[i] = f(s);
    }

    ll k = (1LL << m) - n;
    ll idx = (k - 1) / 2;

    auto check = [&](ll x) {
        ll ct = x;
        rep(i, n) if (a[i] <= x)-- ct;
        return idx <= ct;
    };

    ll ng = -1, ok = (1LL << m) - 1;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    string s(m, '0');
    rep(i, m) {
        int sh = m - i - 1;
        if (ok >> sh & 1) s[i] = '1';
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) cout << solve() << "\n";
    return 0;
}
