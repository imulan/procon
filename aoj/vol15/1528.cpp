#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

struct edge{
    int to;
    ll cost;
};

const ll INF = LLONG_MAX/3;

int main(){
    int L,n;
    scanf(" %d %d", &L, &n);

    vector<int> x;
    x.pb(0);
    x.pb(L);

    vector<int> p(n),d(n),t(n);
    rep(i,n){
        scanf(" %d %d %d", &p[i], &d[i], &t[i]);
        x.pb(p[i]);
        x.pb(p[i]+d[i]);
    }

    sort(all(x));
    x.erase(unique(all(x)), x.end());

    int X = x.size();
    vector<vector<edge>> G(X);

    auto ADD = [&](int u, int v, ll w){
        G[u].pb({v,w});
    };

    rep(i,X-1) ADD(i, i+1, x[i+1]-x[i]);
    rep(i,n){
        int u = lower_bound(all(x), p[i]) - x.begin();
        int v = lower_bound(all(x), p[i]+d[i]) - x.begin();
        ADD(u, v, t[i]);
    }

    vector<ll> dp(X,INF);
    dp[0] = 0;
    rep(i,X)for(const auto &e:G[i]) dp[e.to] = min(dp[e.to], dp[i]+e.cost);

    printf("%lld\n", dp[X-1]);
    return 0;
}
