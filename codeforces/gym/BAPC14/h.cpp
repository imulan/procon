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

using P = pair<ll,int>;

using pi = pair<int,int>;
using D = pair<ll,pi>;

struct edge{ int to; ll cost; };

const int N = 1000;
const ll INF = LLONG_MAX/3;
vector<edge> G[N];

void solve(){
    rep(i,N) G[i].clear();

    int n,m,s;
    ll cap;
    scanf(" %d %d %d %lld", &n, &m, &s, &cap);

    rep(i,m){
        int a,b,f;
        scanf(" %d %d %d", &a, &b, &f);
        --a;
        --b;
        G[a].pb({b,f});
        G[b].pb({a,f});
    }

    vector<int> gs(s+1);
    vector<ll> price(s+1);
    rep(i,s){
        scanf(" %d %lld", &gs[i], &price[i]);
        --gs[i];
    }

    int start,goal;
    scanf(" %d %d", &start, &goal);
    --start;
    --goal;

    gs[s] = goal;
    ++s;

    auto dijkstra = [&](int from){
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<ll> dist(n,INF);
        dist[from] = 0;
        pq.push({0,from});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int v = now.se;
            if(now.fi > dist[v]) continue;
            for(const auto &e:G[v]){
                if(dist[e.to] > dist[v]+e.cost){
                    dist[e.to] = dist[v]+e.cost;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        vector<ll> ret(s);
        rep(i,s) ret[i] = dist[gs[i]];
        return ret;
    };

    vector<vector<ll>> d(s);
    rep(i,s) d[i] = dijkstra(gs[i]);
    // rep(i,s) dbg(d[i]);

    vector<vector<ll>> cand_cap(s);
    vector<int> sz(s);
    rep(i,s){
        vector<ll> cnd;

        rep(j,s)if(d[i][j]<cap) cnd.pb(d[i][j]);
        cnd.pb(cap);

        sort(all(cnd));
        cnd.erase(unique(all(cnd)), cnd.end());

        cand_cap[i] = cnd;
        sz[i] = cnd.size();
    }

    int start_idx = 0;
    while(gs[start_idx] != start) ++start_idx;

    vector<vector<ll>> dp(s,vector<ll>(s+1,INF));

    priority_queue<D, vector<D>, greater<D>> pq;
    dp[start_idx][0] = 0;
    pq.push({0,{start_idx,0}});

    while(!pq.empty()){
        D now = pq.top();
        pq.pop();

        int v = now.se.fi, idx = now.se.se;

        if(v == s-1) continue;
        if(now.fi > dp[v][idx]) continue;

        // 補給
        if(idx+1<sz[v]){
            ll add = price[v] * (cand_cap[v][idx+1]-cand_cap[v][idx]);
            if(dp[v][idx+1] > dp[v][idx] + add){
                dp[v][idx+1] = dp[v][idx] + add;
                pq.push({dp[v][idx+1], {v,idx+1}});
            }
        }

        // 移動
        int rem = cand_cap[v][idx];
        rep(i,s)if(i!=v){
            if(d[v][i] <= rem){
                int rrem = rem-d[v][i];

                int nidx = lower_bound(all(cand_cap[i]), rrem) - cand_cap[i].begin();

                ll add = price[i] * (cand_cap[i][nidx] - rrem);
                if(dp[i][nidx] > dp[v][idx] + add){
                    dp[i][nidx] = dp[v][idx] + add;
                    pq.push({dp[i][nidx], {i,nidx}});
                }
            }
        }
    }

    // rep(i,s){
    //     rep(j,s+1) printf(" dp[%d][%d] = %lld\n", i,j,dp[i][j]);
    //     puts("");
    // }

    ll ans = INF;
    rep(i,s-1)rep(j,cand_cap[i].size()){
        if(d[i][s-1] <= cand_cap[i][j]) ans = min(ans,dp[i][j]);
    }
    printf("%lld\n", ans);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
