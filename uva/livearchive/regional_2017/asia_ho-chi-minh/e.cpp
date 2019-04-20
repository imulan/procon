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

using pi = pair<ll,int>;

struct edge{
    int to;
    int cap;
    ll cost;
    int rev;
};

int V;
const int MAX_V = 2020;
const ll INF = LLONG_MAX/3;
vector<edge> G[MAX_V];
ll h[MAX_V];
ll dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

bool vis[MAX_V];

void add_edge(int from, int to, int cap, ll cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

ll min_cost_flow(int s, int t, int f){
    ll res = 0;
    fill(h,h+V,0);
    while(f>0){
        // dbg(f);
        fill(dist,dist+V,INF);

        // dist[s] = 0;
        // rep(_,2){
        //     fill(vis,vis+V,false);

        //     while(1){
        //         int v=-1;
        //         rep(i,V){
        //             if(!vis[i] && (v==-1||dist[i]<dist[v])) v=i;
        //         }
        //         if(v==-1) break;
        //         vis[v] = true;
        //         rep(i,G[v].size()){
        //             edge &e = G[v][i];
        //             if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
        //                 dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
        //                 prevv[e.to] = v;
        //                 preve[e.to] = i;
        //             }
        //         }
        //     }
        // }
        // rep(i,V) dbg(dist[i]);

        priority_queue<pi,vector<pi>,greater<pi>> pq;
        dist[s] = 0;
        pq.push({0,s});
        while(!pq.empty()){
            pi p = pq.top();
            pq.pop();
            int v = p.se;
            if(p.fi>dist[v]) continue;
            rep(i,G[v].size()){
                edge &e = G[v][i];
                if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push({dist[e.to],e.to});
                }
            }
        }

        if(dist[t]==INF) return res;
        rep(v,V) h[v] += dist[v];

        int d = f;
        for(int v=t; v!=s; v=prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];

        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main(){
    int m,n,k;
    scanf(" %d %d %d", &m, &n, &k);
    V = m+n+2;
    int S = m+n, T = S+1;
    rep(i,n) add_edge(S,i,1,0);
    rep(i,m) add_edge(n+i,T,1,0);

    vector<vector<int>> C(n,vector<int>(m));
    rep(i,k){
        int c,g,p;
        scanf(" %d %d %d", &c, &g, &p);
        --c;
        --g;
        C[c][g] = p;
        // add_edge(c,n+g,1,-p);
    }

    rep(i,n)rep(j,m) add_edge(i,n+j,1,-C[i][j]);

    ll ans = -min_cost_flow(S,T,n);
    vector<pi> p;
    rep(i,m){
        for(const auto &e:G[n+i]){
            if(e.to<n && e.cap>0){
                p.pb({e.to+1, i+1});
            }
        }
    }

    int P = p.size();
    printf("%d\n", ans);
    printf("%d\n", P);
    rep(i,P) printf("%d %d\n", p[i].fi, p[i].se);
    return 0;
}
