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

struct edge{ int to,cap,rev; };

const int MAX_V = 40004; // TODO:initialize
const int F_INF = 19191919; // TODO:initialize
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
        while((f=dinic_dfs(s,t,F_INF))>0) flow+=f;
    }
}

int solve(){
    rep(i,MAX_V) G[i].clear();

    int N;
    cin >>N;

    vector<vector<int>> a(N,vector<int>(N));
    rep(i,N)rep(j,N) scanf(" %d", &a[i][j]);

    int S = N*2*N*2, T = S+1;
    rep(i,N*2*N){
        add_edge(S, i, 1);
        add_edge(N*2*N+i, T, 1);
    }

    auto cv = [&](int col){
        if(col>0) return col-1;
        return N+(-col-1);
    };

    rep(i,N)rep(j,N){
        int u = i*2*N + cv(a[i][j]);
        int v = N*2*N + j*2*N + cv(a[i][j]);
        // printf(" %d -> %d\n", u,v);
        add_edge(u, v, 1);
    }

    return N*N - max_flow(S,T);
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}
