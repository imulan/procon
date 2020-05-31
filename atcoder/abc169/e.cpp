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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<ll> sa(a), sb(b);
    sort(all(sa));
    sort(all(sb));

    ll ma, mb;
    if (n % 2 == 1) {
        ma = sa[n / 2];
        mb = sb[n / 2];
    } else {
        ma = sa[(n - 1) / 2] + sa[n / 2];
        mb = sb[(n - 1) / 2] + sb[n / 2];
    }
    cout << mb - ma + 1 << "\n";
    return 0;
}
