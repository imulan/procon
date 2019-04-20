#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct edge{ int to,cap,rev; };
const int MAX_V = 333;
const int F_INF = 191919;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb({to, cap, (int)G[to].size()});
    G[to].pb({from, 0, (int)G[from].size()-1});
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;
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
    for(int &i = iter[v]; i<(int)G[v].size(); ++i){
        edge &e = G[v][i];
        if(e.cap>0 && level[v] < level[e.to]){
            int d = dinic_dfs(e.to, t, min(f, e.cap));
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
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow += f;
    }
}


int main(){
    int n;
    scanf(" %d", &n);
    vector<int> w(n),l(n);
    rep(i,n) scanf(" %d %d", &w[i], &l[i]);

    int m;
    scanf(" %d", &m);
    vector<int> t(m);
    rep(i,m) scanf(" %d", &t[i]);

    int S = 2*n+m, T = S+1;

    rep(i,n){
        if(w[i]==0) add_edge(S,2*i,1);
        add_edge(2*i,2*i+1,1);

        rep(j,n)if(i!=j){
            if(l[i]>=w[j]) add_edge(2*i+1, 2*j, 1);
        }

        rep(j,m){
            if(l[i]>=t[j]) add_edge(2*i+1, 2*n+j, 1);
        }
    }

    rep(i,m) add_edge(2*n+i, T, 1);

    int f = max_flow(S,T);

    if(f != m){
        printf("impossible\n");
        return 0;
    }

    rep(i,m){
        vector<int> v;
        int now = 2*n+i;
        while(now != S){
            for(const auto &e:G[now]){
                if(e.cap>0 && (e.to==S || e.to<2*n)){
                    now = e.to;
                    break;
                }
            }
            if(now == S) break;

            assert(now%2==1);
            v.pb(now/2);
            --now;
        }

        reverse(all(v));
        int V = v.size();
        rep(j,V) printf("%d%c", v[j]+1, " \n"[j==V-1]);
    }

    return 0;
}