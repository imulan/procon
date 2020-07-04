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

const ll INF = LLONG_MAX / 3;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    set<ll> used;
    queue<ll> que;
    rep(i, n) {
        used.insert(x[i]);
        for (int j : {-1, 1}) que.push(x[i] + j);
    }

    vector<ll> y;
    while (!que.empty()) {
        ll a = que.front();
        que.pop();
        if (used.count(a)) continue;

        used.insert(a);
        y.pb(a);
        if (y.size() == m) break;
        for (int i : {-1, 1}) que.push(a + i);
    }

    x.pb(-INF);
    x.pb(INF);
    sort(all(x));

    ll ans = 0;
    for (ll i : y) {
        ll add = INF;
        auto itr = lower_bound(all(x), i);
        add = min(add, abs(*itr - i));

        --itr;
        add = min(add, abs(*itr - i));
        ans += add;
    }

    cout << ans << "\n";
    rep(i, m) cout << y[i] << " \n"[i == m - 1];
    return 0;
}
