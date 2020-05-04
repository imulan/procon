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

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    if (n <= (ll)d * (k - 1)) {
        cout << -1 << "\n";
        return 0;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    int idx = 0;
    int pre = -n;
    rep(i, k) {
        int rem = k - 1 - i;
        int L = n - 1 - d * rem;
        while (idx <= L) {
            pq.push({a[idx], idx});
            ++idx;
        }

        int ans = -1;
        while (!pq.empty()) {
            pi p = pq.top();
            pq.pop();
            if (p.se - pre >= d) {
                pre = p.se;
                ans = p.fi;
                break;
            }
        }

        cout << ans << " \n"[i == k - 1];
    }

    return 0;
}
