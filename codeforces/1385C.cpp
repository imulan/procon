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

int solve() {
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i, n) scanf(" %d", &a[i]);
    reverse(all(a));

    bool inc = true;
    int idx = 1;
    while (idx < n) {
        if (inc) {
            if (a[idx - 1] > a[idx]) {
                inc = false;
                continue;
            }
        } else {
            if (a[idx - 1] < a[idx]) break;
        }
        ++idx;
    }
    return n - idx;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) printf("%d\n", solve());
    return 0;
}
