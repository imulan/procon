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
    string s;
    cin >> n >> s;

    set<int> pos[2];
    rep(i, n) pos[s[i] - '0'].insert(i);
    rep(i, 2) pos[i].insert(n);

    int k = 0;
    vector<int> a(n);
    while (pos[0].size() > 1 || pos[1].size() > 1) {
        ++k;

        int pi = (*pos[0].begin() > *pos[1].begin());
        int now = *pos[pi].begin();
        while (now < n) {
            a[now] = k;
            pos[pi].erase(now);
            now = *pos[!pi].lower_bound(now);
            pi = !pi;
        }
    }

    cout << k << "\n";
    rep(i, n) cout << a[i] << " \n"[i == n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
