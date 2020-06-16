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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    map<ll, int> lidx, cnt;
    for (int i = n - 1; i >= 0; --i) {
        lidx[a[i]] = i;
        ++cnt[a[i]];
    }

    vector<ll> pre(a), suf(a);
    rep(i, n - 1) pre[i + 1] += pre[i];
    for (int i = n - 1; i > 0; --i) suf[i - 1] += suf[i];

    ll ans = LLONG_MAX;
    for (const auto& p : lidx) {
        ll x = p.fi;
        int l = p.se, r = l + cnt[x] - 1;

        int need = max(0, k - cnt[x]);
        int precnt = l, sufcnt = n - 1 - r;

        ll presum = 0, sufsum = 0;
        if (l - 1 >= 0) presum = pre[l - 1];
        if (r + 1 < n) sufsum = suf[r + 1];

        int needl, needr;
        auto calc = [&]() {
            ll t = 0;
            if (needl > 0) t += (x - 1) * precnt - presum + needl;
            if (needr > 0) t += sufsum - (x + 1) * sufcnt + needr;
            return t;
        };

        // small first
        needl = min(need, precnt);
        needr = max(0, need - needl);
        ans = min(ans, calc());

        // large first
        needr = min(need, sufcnt);
        needl = max(0, need - needr);
        ans = min(ans, calc());
    }

    cout << ans << "\n";
    return 0;
}
