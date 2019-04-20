#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 3003; // TODO:initialize
const int F_INF = 19191919; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

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
    for(int &i=iter[v]; i<(int)G[v].size(); ++i){
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

int S,T;

bool vis[MAX_V];
int par[MAX_V];
void dfs(int x, int p){
    par[x] = p;
    vis[x] = true;
    for(const auto &e:G[x])if(e.cap>0 && e.to!=p && e.to!=T){
        if(!vis[e.to]){
//            printf(" %d -> %d  CAP %d\n",x,e.to,e.cap);
            dfs(e.to,x);
        }
    }
}

int main(){
    int m,n,k;
    scanf(" %d %d %d", &m, &n, &k);

    S = m+n;
    T = S+1;

    rep(i,n) add_edge(S,m+i,1);
    rep(i,m) add_edge(i,T,1);

    rep(i,k){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        add_edge(m+y,x,1);
    }

    int f = max_flow(S,T);
    int ans = f;

    rep(i,m){
        add_edge(i,T,2);
        int af = max_flow(S,T);
//        printf(" %d %d\n",i,af);
        ans = max(ans, f+af);

        rep(_,af){
            fill(vis,vis+MAX_V,false);
            dfs(i,-1);

            int now = S;
            while(now != i){
                int p = par[now];
//                printf(" %d -> %d\n",now,p);
                for(auto &e:G[now]){
                    if(e.to == p){
//                        printf(" REV CAP %d\n",G[e.to][e.rev].cap);
//                        assert(e.cap==0);
                        e.cap = 1;
                        G[e.to][e.rev].cap = 0;
                        break;
                    }
                }
                now = p;
            }
        }

        for(auto &e:G[i]){
            if(e.to == T){
                if(e.cap + G[T][e.rev].cap == 2){
                    e.cap = 0;
                    G[T][e.rev].cap = 0;
                    break;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}