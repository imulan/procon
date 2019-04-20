#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

struct edge{int to,cap,rev;};

const int MAX_V = 5000;
const int F_INF = 1000000000;
vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v =  que.front();
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

int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); ++i){
        edge &e = G[v][i];
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

const int N = 5000;
int v,e;
int s[N],t[N],c[N];

int main()
{
    cin >>v >>e;
    rep(i,e) cin >>s[i] >>t[i] >>c[i];

    // 全部
    rep(i,e)
    {
        add_edge(s[i],t[i],c[i]);
        add_edge(t[i],s[i],c[i]);
    }

    int F0 = max_flow(0,v-1);

    rep(i,MAX_V) G[i].clear();

    rep(i,e)if(c[i]>1)
    {
        add_edge(s[i],t[i],c[i]);
        add_edge(t[i],s[i],c[i]);
    }

    int F1 = max_flow(0,v-1);

    int ans = F0;
    if(F0-F1>0)
    {
        ans = F0-1;
    }
    if(ans >10000) ans = -1;

    cout << ans << endl;
    return 0;
}
