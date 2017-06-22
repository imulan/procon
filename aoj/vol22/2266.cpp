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

// (行き先, 容量, コスト, 逆辺)
struct edge{
    int to,cap;
    ll cost;
    int rev;
};

int V; // TODO:initialize
const int MAX_V = 30303; // TODO:initialize
const ll INF = 123456789012345LL; // TODO:initialize
vector<edge> G[MAX_V];
ll h[MAX_V]={}; // ポテンシャル
ll dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
ll min_cost_flow(int s, int t, int f, bool neg = false){
    ll res = 0;
    fill(h,h+V,0);
    while(f>0){
        // dijkstraでhを更新
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        if(neg)
        {
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

const ll M=10000000;

vector<int> num[10000];

int main()
{
    int F,n,k;
    scanf(" %d %d %d", &F, &n, &k);
    vector<int> w(n),a(k);
    rep(i,n) scanf(" %d", &w[i]);
    rep(i,k)
    {
        scanf(" %d", &a[i]);
        --a[i];
        num[a[i]].pb(i);
    }

    V = 3*k+3;
    int S=3*k, T=S+1;
    add_edge(S,0,F,0);

    rep(i,k)
    {
        add_edge(3*i, 3*i+1, 1, w[a[i]]);
        add_edge(3*i+1, 3*i+2, 1, -M);
        if(i<k-1)
        {
            add_edge(3*i+2, 3*(i+1), 1, 0);
            add_edge(3*i, 3*(i+1), F-1, 0);
        }
    }

    rep(i,n)
    {
        int SZ = num[i].size();
        rep(j,SZ-1)
        {
            int u=num[i][j], v=num[i][j+1];
            add_edge(3*u+2, 3*v+1, 1, 0);
        }
    }

    add_edge(3*k-3, T, F, 0);
    add_edge(3*k-1, T, 1, 0);

    printf("%lld\n", min_cost_flow(S,T,F,true)+M*k);
    return 0;
}
