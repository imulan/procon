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

using pi = pair<int, int>;
using P = pair<int, pi>;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    priority_queue<P> pq;

    auto PUSH = [&](int l, int r) {
        if (l <= r) {
            int w = r - l + 1;
            pq.push({w, {-l, -r}});
        }
    };

    PUSH(0, n - 1);

    for (int i = 1; i <= n; ++i) {
        P p = pq.top();
        pq.pop();
        int l = -p.se.fi, r = -p.se.se;

        int idx;
        if ((r - l + 1) % 2 == 1)
            idx = (l + r) / 2;
        else
            idx = (l + r - 1) / 2;
        a[idx] = i;

        PUSH(l, idx - 1);
        PUSH(idx + 1, r);
    }

    rep(i, n) cout << a[i] << " \n"[i == n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
