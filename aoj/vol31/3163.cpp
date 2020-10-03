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

const int N = 100010;
ll L[N];
vector<int> G[N];

ll sL = 0;

ll s[N], d[N];
void calc(int v, int p) {
    s[v] = L[v];
    for (int e : G[v])
        if (e != p) {
            d[e] = d[v] + 1;
            calc(e, v);
            s[v] += s[e];
        }
}

ll ans[N];
void dfs(int v, int p, ll now) {
    ans[v] = now;
    for (int e : G[v])
        if (e != p) {
            ll t = now - s[e] + (sL - s[e]);
            dfs(e, v, t);
        }
}

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        cin >> L[i];
        sL += L[i];
    }
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    calc(0, -1);

    ll v0 = 0;
    rep(i, n) v0 += L[i] * d[i];

    dfs(0, -1, v0);

    rep(i, n) cout << ans[i] << "\n";
    return 0;
}
