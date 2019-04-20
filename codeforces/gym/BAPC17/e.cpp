#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back

struct edge{int to,cap,rev;};

const int MAX_V = 555;
const int F_INF = 10101010;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
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

using pi = pair<int,int>;

int main(){
    int n,B,R;
    cin >>n >>B >>R;

    vector<pi> b(B),r(R);
    rep(i,B){
        int x,y;
        cin >>x >>y;
        b[i] = {x,y};
    }
    rep(i,R){
        int x,y;
        cin >>x >>y;
        r[i] = {x,y};
    }

    auto dist = [&](pi p, pi q){
        double dx = p.fi-q.fi, dy = p.se-q.se;
        return sqrt(dx*dx+dy*dy);
    };

    vector<vector<double>> D(B,vector<double>(R));
    rep(i,B)rep(j,R){
        D[i][j] = dist(b[i],r[j]);
        // printf(" %d %d %f\n",i,j,D[i][j]);
    }

    auto valid = [&](double m){
        rep(i,MAX_V) G[i].clear();
        int S = R+B, T = S+1;

        rep(i,B) add_edge(S,i,1);
        rep(i,R) add_edge(B+i,T,1);
        rep(i,B)rep(j,R){
            if(D[i][j]<=m) add_edge(i,B+j,1);
        }

        int f = max_flow(S,T);
        int STABLE_SET = R+B - f;
        // printf(" %d %d\n", f,STABLE_SET);
        return STABLE_SET >= n;
    };

    double ok=0, ng=100000;
    rep(loop,60){
        double mid = (ng+ok)/2;
        if(valid(mid)) ok=mid;
        else ng=mid;
    }
    printf("%.10f\n",ok);
    return 0;
}
