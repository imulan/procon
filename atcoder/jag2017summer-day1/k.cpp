#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> c(n), g(n);
    rep(i, n) cin >> c[i] >> g[i];
    vector<ll> t(n);
    rep(i, n) t[i] = c[i] + g[i];

    ll s = accumulate(g.begin(), g.end(), 0ll);
    sort(t.begin(), t.end());

    ll a = 0ll;
    rep(i, n) {
        if (a + t[i] > s) {
            cout << i << endl;
            return 0;
        }
        a += t[i];
    }
    cout << n << endl;
    return 0;
}
