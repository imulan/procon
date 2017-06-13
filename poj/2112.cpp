#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> P;

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 255; // TODO:initialize
const int F_INF = 364364; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,G[to].size()});
    G[to].pb({from,0,G[from].size()-1});
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをdfsで探す
int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<G[v].size(); ++i){
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            int d = dinic_dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dinic_dfs(s,t,F_INF))>0) flow+=f;
    }
}

const int INF=123456789;
int d[MAX_V][MAX_V];

int main()
{
    int K,C,M;
    scanf(" %d %d %d", &K, &C, &M);

    int n = K+C;
    fill(d[0],d[MAX_V],INF);
    rep(i,n)rep(j,n)
    {
        int a;
        scanf(" %d", &a);
        if(a>0) d[i][j]=a;
    }
    rep(i,n) d[i][i]=0;

    rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    vector<int> ds;
    vector<P> pp;
    rep(i,K)rep(j,C)if(d[i][K+j]<INF)
    {
        ds.pb(d[i][K+j]);
        pp.pb(P(d[i][K+j],pi(i,K+j)));
    }
    sort(all(ds));
    ds.erase(unique(all(ds)),ds.end());
    sort(all(pp));

    int DS = ds.size();

    int S = MAX_V-2, T = MAX_V-1;
    rep(i,K) add_edge(S,i,M);
    rep(i,C) add_edge(K+i,T,1);

    int f = 0, idx = 0;
    int pidx = 0;
    while(idx<DS)
    {
        while(ds[idx] == pp[pidx].fi)
        {
            int u = pp[pidx].se.fi, v = pp[pidx].se.se;
            add_edge(u,v,1);
            ++pidx;
        }

        f += max_flow(S,T);

        if(f>=C) break;
        ++idx;
    }

    printf("%d\n", ds[idx]);
    return 0;
}
