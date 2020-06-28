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
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
    }

    const int INF = 2 * n;
    vector<int> d(n, INF);

    vector<int> v;
    int ct = 0;
    int now = 0;
    while (d[now] == INF) {
        v.pb(now);
        d[now] = ct++;
        now = a[now];
    }

    int ans;
    if (k < ct)
        ans = v[k];
    else {
        int loop = ct - d[now];

        k -= ct;
        k %= loop;
        ans = v[d[now] + k];
    }
    cout << ans + 1 << "\n";
    return 0;
}
