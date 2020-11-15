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

struct edge {
    int to;
    ll cost;
};

using P = pair<ll, int>;

const int N = 100010;
const ll INF = LLONG_MAX / 3;
vector<edge> G[N];
ll d[N];

int main() {
    int n, m, x[3];
    cin >> n >> m;
    rep(i, 3) cin >> x[i];

    string s;
    cin >> s;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    // n:warpA, n+1:warpB, n+2:warpC
    rep(i, n) {
        if (s[i] == 'A') {
            G[i].pb({n, 0});
            G[n + 1].pb({i, x[0]});
            G[n + 2].pb({i, x[1]});
        } else if (s[i] == 'B') {
            G[i].pb({n + 1, 0});
            G[n].pb({i, x[0]});
            G[n + 2].pb({i, x[2]});
        } else {
            G[i].pb({n + 2, 0});
            G[n].pb({i, x[1]});
            G[n + 1].pb({i, x[2]});
        }
    }

    fill(d, d + N, INF);
    d[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.se;
        if (d[v] < p.fi) continue;
        for (const auto& e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                pq.push({d[e.to], e.to});
            }
        }
    }
    cout << d[n - 1] << "\n";
    return 0;
}
