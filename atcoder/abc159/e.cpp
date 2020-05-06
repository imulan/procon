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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    auto calc = [&](int mask) {
        int t = __builtin_popcount(mask);

        vector<int> b(h);
        int bi = 0;
        rep(i, h) {
            b[i] = bi;
            if (i < h - 1 && mask >> i & 1) ++bi;
        }
        const int B = bi + 1;

        vector<int> ct(B);
        rep(i, w) {
            vector<int> add(B);
            rep(j, h) add[b[j]] += s[j][i] - '0';

            bool ok = true;
            rep(j, B) if (ct[j] + add[j] > k) ok = false;
            if (ok) {
                rep(j, B) ct[j] += add[j];
            } else {
                ++t;
                ct = add;
            }

            rep(j, B) if (ct[j] > k) return INT_MAX;
        }

        return t;
    };

    int ans = h + w - 2;
    rep(mask, 1 << (h - 1)) ans = min(ans, calc(mask));
    cout << ans << "\n";
    return 0;
}
