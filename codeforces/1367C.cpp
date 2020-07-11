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

const int INF = 19191919;

int solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    set<int> a;
    a.insert(-INF);
    a.insert(INF);
    rep(i, n) if (s[i] == '1') a.insert(i);

    int ans = 0;
    rep(i, n) if (s[i] == '0') {
        auto itr = a.lower_bound(i);
        int R = *itr;
        --itr;
        int L = *itr;

        if (i - L > k && R - i > k) {
            ++ans;
            a.insert(i);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}
