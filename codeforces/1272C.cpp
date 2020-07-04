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
    int n, k;
    string s;
    cin >> n >> k >> s;

    set<char> av;
    rep(i, k) {
        char c;
        cin >> c;
        av.insert(c);
    }

    vector<bool> b(n);
    rep(i, n) {
        if (av.count(s[i])) b[i] = true;
    }

    ll ans = 0;
    int idx = 0;
    while (idx < n) {
        if (b[idx]) {
            int l = idx;
            while (idx < n && b[idx]) ++idx;

            ll w = idx - l;
            ans += w * (w + 1) / 2;
        } else
            ++idx;
    }
    cout << ans << "\n";
    return 0;
}
