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

using P = pair<char, int>;
const int A = 26;

int main() {
    int q;
    cin >> q;

    deque<P> dq;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            int x;
            cin >> c >> x;
            dq.push_back({c, x});
        } else {
            int d;
            cin >> d;

            vector<int> ct(A);
            while (d > 0 && !dq.empty()) {
                P v = dq.front();
                dq.pop_front();

                int idx = v.fi - 'a';

                if (v.se > d) {
                    v.se -= d;
                    dq.push_front(v);

                    ct[idx] += d;
                    d = 0;
                } else {
                    ct[idx] += v.se;
                    d -= v.se;
                }
            }

            ll ans = 0;
            for (int i : ct) ans += (ll)i * i;
            cout << ans << "\n";
        }
    }
    return 0;
}
