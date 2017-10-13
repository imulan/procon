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
const int MAX_V = 40; // TODO:initialize
const int INF = 10000; // TODO:initialize
vector<edge> G[MAX_V];
int h[MAX_V]; // ポテンシャル
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
int min_cost_flow(int s, int t, int f, bool neg = false){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        if(neg)
        {
            // bellman-fordでhを更新
            neg = false;
            bool update;
            do{
                update = false;
                rep(v,V){
                    if(dist[v] == INF) continue;
                    rep(i,G[v].size()){
                        edge &e = G[v][i];
                        if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
                            dist[e.to]=dist[v]+e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }while(update);
        }
        else
        {
            // dijkstraでhを更新
            pq.push(pi(0,s));
            while(!pq.empty()){
                pi p = pq.top();
                pq.pop();
                // dbg(p);
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
        }

        // これ以上流せない
        if(dist[t]==INF) return -191919;

        rep(v,V) h[v] += dist[v];

        // s-t間の最短路に沿って目一杯流す
        int d=f;
        for(int v=t; v!=s; v=prevv[v])
        {
            d = min(d,G[prevv[v]][preve[v]].cap);
            // dbg(v);
        }

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

const int M = 1000000;
bool door[10][26]={};
int cost[10][26];

int main()
{
    int n;
    scanf(" %d", &n);

    while(n--)
    {
        char c;
        int d;
        scanf(" %c %d", &c, &d);
        door[d][c-'A'] = true;
    }

    fill(cost[0],cost[10],M*100);
    int m;
    scanf(" %d", &m);
    while(m--)
    {
        char c;
        int d,e;
        scanf(" %c %d %d", &c, &d, &e);
        cost[d][c-'A'] = min(cost[d][c-'A'], e);
    }

    int S = 36, T = S+1;
    V = T+1;

    int ans = M;
    rep(mask,1<<10)
    {
        rep(i,V) G[i].clear();

        int lb = 0;

        // source to number
        rep(i,10)
        {
            if(mask>>i&1)
            {
                add_edge(S,i,1,-M);
                add_edge(S,i,INF-1,0);
                ++lb;
            }
            else
            {
                add_edge(S,i,INF,0);
            }
        }

        // number to alphabet
        rep(i,10)rep(j,26) add_edge(i,10+j,1,cost[i][j]);

        // alphabet to sink
        bool must[26]={};
        rep(i,26)
        {
            int amask = 0;
            rep(j,10)if(door[j][i]) amask |= 1<<j;

            rep(j,10)
            {
                if((amask>>j&1) && !(mask>>j&1)) must[i]=true;
            }
        }

        rep(i,26)
        {
            if(must[i])
            {
                add_edge(10+i,T,1,-M);
                add_edge(10+i,T,INF-1,0);
                ++lb;
            }
            else
            {
                add_edge(10+i,T,INF,0);
            }
        }

        int cur = 0;
        rep(ff,36)
        {
            int res = min_cost_flow(S,T,1);
            if(res==-191919) break;

            cur += res;
            ans = min(ans,cur+M*lb);
        }
    }

    if(ans==M) ans = -1;
    printf("%d\n", ans);
    return 0;
}
