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

using pi = pair<int,int>;

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = 2525; // TODO:initialize
const int INF = 1010101010; // TODO:initialize
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

const int M=10;
int d[100][100];

int main()
{
    int n,m,R;
    while(scanf(" %d %d %d", &n, &m, &R),n)
    {
        fill(d[0],d[100],INF);
        rep(i,n) d[i][i]=0;
        rep(i,m)
        {
            int u,v,c;
            scanf(" %d %d %d", &u, &v, &c);
            d[u][v] = d[v][u] = c;
        }

        rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

        vector<pi> req(R);
        rep(i,R)
        {
            int p,t;
            scanf(" %d %d", &p, &t);
            req[i] = pi(t,p);
        }
        sort(all(req));

        rep(i,MAX_V) G[i].clear();
        V = MAX_V;
        int S = MAX_V-2, T = S+1;
        rep(i,n)
        {
            add_edge(S,2*R+i,1,0);
            add_edge(2*R+i,T,1,0);
        }
        rep(i,R)
        {
            add_edge(2*i,2*i+1,1,-M);
            add_edge(2*i+1,T,1,0);
        }
        rep(i,R)for(int j=i+1; j<R; ++j)
        {
            int ti = req[i].fi, tj = req[j].fi;
            int u = req[i].se, v = req[j].se;
            if(d[u][v]<=tj-ti) add_edge(2*i+1,2*j,1,0);
        }

        int ans = 0;
        int sum = 0;
        while(1)
        {
            rep(i,R) add_edge(2*R+ans,2*i,1,0);
            ++ans;
            sum += min_cost_flow(S,T,1);
            if(sum == -R*M) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
