#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = 2222; // TODO:initialize
const ll INF = LLONG_MAX/3; // TODO:initialize
vector<edge> G[MAX_V];
ll h[MAX_V]; // ポテンシャル
ll dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,G[to].size()});
    G[to].pb({from,0,-cost,G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
ll min_cost_flow(int s, int t, int f){
    ll res = 0;
    fill(h,h+V,0);
    while(f>0){
        // dijkstraでhを更新
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        pq.push(pi(0,s));
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
                    pq.push(pi(dist[e.to],e.to));
                }
            }
        }

        // これ以上流せない
        if(dist[t]==INF) return -1;

        rep(v,V) h[v] += dist[v];

        // s-t間の最短路に沿って目一杯流す
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

int main()
{
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &b[i]);

    int S=0,T=n+1;
    V = n+2;

    rep(i,n) add_edge(S,i+1,1,a[i]);
    rep(i,n) add_edge(i+1,T,1,b[i]);
    rep(i,n-1) add_edge(i+1,i+2,k,0);

    printf("%lld\n", min_cost_flow(S,T,k));
    return 0;
}
