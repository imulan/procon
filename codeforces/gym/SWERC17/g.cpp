#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fi first
#define se second
#define pb push_back

using pi = pair<int,int>;

struct edge{
    int to,cap,cost,rev;
};

int V;
const int MAX_V = 2010;
const int INF = 191919191;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
bool used[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    // printf(" %d -> %d cap %d cost %d\n",from,to,cap,cost);
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        // printf(" f %d\n", f);
        // priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s] = 0;

        fill(used,used+V,false);
        while(1){
            int v = -1;
            rep(i,V){
                if(!used[i] && (v==-1 || dist[i]<dist[v])) v = i;
            }
            if(v==-1) break;

            used[v] = true;
            rep(i,G[v].size()){
                edge &e = G[v][i];
                // printf(" nx %d\n",e.to);
                if(e.cap>0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    // pq.push({dist[e.to],e.to});
                }
            }
        }

        if(dist[t]==INF) return -1;
        rep(v,V) h[v] += dist[v];

        int d=f;
        for(int v=t; v!=s; v=prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap);
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

inline int mdist(const pi &p, const pi &q){
    return abs(p.fi-q.fi) + abs(p.se-q.se);
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> b(n),c(m);
    rep(i,n) scanf(" %d %d", &b[i].fi, &b[i].se);
    rep(i,m) scanf(" %d %d", &c[i].fi, &c[i].se);

    pi rest;
    scanf(" %d %d", &rest.fi, &rest.se);

    int S = m+n+1, T = S+1;
    V = T+1;

    add_edge(S,0,n-1,0);
    rep(i,m) add_edge(S,i+1,1,0);

    rep(i,n) add_edge(0,m+1+i,1,2*mdist(rest,b[i]));
    rep(i,m)rep(j,n) add_edge(i+1,m+1+j,1,mdist(c[i],b[j])+mdist(b[j],rest));

    rep(i,n) add_edge(m+1+i,T,1,0);

    printf("%d\n", min_cost_flow(S,T,n));
    return 0;
}
