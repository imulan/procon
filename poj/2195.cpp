#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = 222; // TODO:initialize
const int INF = 19191919; // TODO:initialize
vector<edge> G[MAX_V];
int h[MAX_V]; // ポテンシャル
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        // dijkstraでhを更新
        priority_queue< pi, vector<pi>, greater<pi> > pq;
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
    // cin.tie(0);ios::sync_with_stdio(false);
    int H,W;
    while(cin >>H >>W,H)
    {
        rep(i,MAX_V) G[i].clear();

        vector<string> s(H);
        rep(i,H) cin >>s[i];

        vector<pi> man,house;
        rep(i,H)rep(j,W)
        {
            if(s[i][j]=='m') man.pb(pi(i,j));
            if(s[i][j]=='H') house.pb(pi(i,j));
        }

        int n = man.size();
        V = 2*n+2;
        int S = 2*n, T = S+1;
        rep(i,n) add_edge(S,i,1,0);
        rep(i,n) add_edge(n+i,T,1,0);
        rep(i,n)rep(j,n)
        {
            int d = abs(man[i].fi-house[j].fi) + abs(man[i].se-house[j].se);
            add_edge(i,n+j,1,d);
        }

        printf("%d\n", min_cost_flow(S,T,n));
    }
    return 0;
}
