#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

struct edge{int to,cap,rev;};

const int MAX_V = 5010;
const int F_INF = 123456789;
vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, int cap){
    // printf(" %d -> %d\n", from,to);
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
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
        while((f=dinic_dfs(s,t,F_INF))>0) flow += f;
    }
}

int main()
{
    int n;
    cin >>n;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    vector<int> group(n+1,-1);
    group[0] = 0;
    rep(i,n)
    {
        int id = i+1;
        group[id] = !group[p[i]];
    }

    int A = 0;
    rep(i,n+1) A += !group[i];

    // printf(" A= %d\n", A);
    // rep(i,n+1) printf(" group[%d] = %d\n", i,group[i]);

    int S = n+1, T = n+2;
    add_edge(S,0,1);

    int ans = 0;
    rep(i,n)
    {
        int id = i+1;
        if(group[id]==0)
        {
            add_edge(S,id,1);
            add_edge(id,p[i],1);
        }
        else
        {
            add_edge(p[i],id,1);
            add_edge(id,T,1);
        }
        ans += max_flow(S,T);
        cout << ans << endl;
    }
    return 0;
}
