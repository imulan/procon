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
const int MAX_V = 2500; // TODO:initialize
const int INF = 123456789; // TODO:initialize
vector<edge> G[MAX_V];
int h[MAX_V]; // ポテンシャル
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,G[to].size()});
    G[to].pb({from,0,-cost,G[from].size()-1});
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

struct Point{ int x,y; };

const int C=10;

int m,n;
Point r[3],p[1000];
int s[1000],t[1000];

inline int d2(Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main()
{
    scanf(" %d", &m);
    rep(i,m) scanf(" %d %d", &r[i].x, &r[i].y);
    scanf(" %d", &n);
    rep(i,n) scanf(" %d %d %d %d", &p[i].x, &p[i].y, &s[i], &t[i]);

    V = 2*n + m + 2;

    int S = 2*n, T = 2*n+1;

    vector<int> M(m);
    rep(i,m) M[i] = 2*n+2+i;

    rep(i,m)
    {
        add_edge(S,M[i],1,0);
        add_edge(M[i],T,1,0);
    }

    rep(i,n)
    {
        add_edge(2*i,2*i+1,1,-C);
        add_edge(2*i+1,T,1,0);
    }

    rep(i,m)rep(j,n)
    {
        if(d2(r[i],p[j]) <= s[j]*s[j]) add_edge(M[i],2*j,1,0);
    }

    rep(i,n)for(int j=i+1; j<n; ++j)
    {
        if(d2(p[i],p[j]) <= (s[j]-t[i])*(s[j]-t[i])) add_edge(2*i+1,2*j,1,0);
    }

    printf("%s\n", (min_cost_flow(S,T,m)==-C*n)?"YES":"NO");
    return 0;
}
