#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 404; // TODO:initialize
const int F_INF = 1919; // TODO:initialize
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

int k[200][200];

int solve(int g, int b, int m)
{
    rep(i,MAX_V) G[i].clear();

    memset(k,0,sizeof(k));
    rep(i,m)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        k[x-1][y-1]=1;
    }

    int S = MAX_V-2, T = MAX_V-1;

    rep(i,g) add_edge(S,i,1);
    rep(i,b) add_edge(g+i,T,1);
    rep(i,g)rep(j,b)if(!k[i][j]) add_edge(i,g+j,1);

    int ans = max(g,b);
    ans = max(ans, g+b-max_flow(S,T));
    return ans;
}

int main()
{
    int t=1;
    int g,b,m;
    while(scanf(" %d %d %d", &g, &b, &m),g) printf("Case %d: %d\n", t++, solve(g,b,m));
    return 0;
}
