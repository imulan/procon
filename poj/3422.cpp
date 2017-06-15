#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
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
const int MAX_V = 5555; // TODO:initialize
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

inline int getnum(int i, int j, int n)
{
    return i*n+j;
}

int main()
{
    int n,k;
    cin >>n >>k;

    V = 2*n*n;

    #define IN(x,y) (0<=x && x<n && 0<=y && y<n)
    rep(i,n)rep(j,n)
    {
        int f;
        cin >>f;

        int now = getnum(i,j,n);
        add_edge(2*now,2*now+1,1,-f);
        add_edge(2*now,2*now+1,15,0);

        int dx[2]={1,0},dy[2]={0,1};
        rep(d,2)
        {
            int nx = j+dx[d], ny = i+dy[d];
            if(!IN(nx,ny)) continue;

            int nxt = getnum(ny,nx,n);
            add_edge(2*now+1,2*nxt,15,0);
        }
    }

    int S = 0, T = 2*getnum(n-1,n-1,n)+1;
    cout << -min_cost_flow(S,T,k) << endl;
    return 0;
}
