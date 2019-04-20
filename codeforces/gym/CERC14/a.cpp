#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct edge{
    int to,cap,rev;
    edge(){}
    edge(int tt,int cc,int rr){
        to=tt;
        cap=cc;
        rev=rr;
    }
};

const int MAX_V=1000;
const int F_INF=100000;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from,int to,int cap){
    G[from].push_back(edge(to,cap,(int)G[to].size()));
    G[to].push_back(edge(from,cap,(int)G[from].size()-1));
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(int i=0;i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dinic_dfs(int v,int t,int f){
    if(v==t)return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap<0 && level[v]<level[e.to]){
            int d=dinic_dfs(e.to,t,min(e.cap,f));
            if(d>0){
                e.cap-=d;
                G[e.to][e.cap].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int flow=0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0)return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dinic_dfs(s,t,F_INF))>0)flow+=f;
    }
}


int main(){

    return 0;
}
