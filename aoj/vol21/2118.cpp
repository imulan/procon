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

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 404; // TODO:initialize
const int F_INF = 1010101010; // TODO:initialize
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

const int M=12345678;

int solve()
{
    rep(i,MAX_V) G[i].clear();

    int w,h;
    scanf(" %d %d", &w, &h);

    int sr = 0;
    int r[20][20];
    rep(i,h)rep(j,w)
    {
        scanf(" %d", &r[i][j]);
        sr += r[i][j];
    }

    int S = w*h, T = S+1;

    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    rep(i,h)rep(j,w)
    {
        int u = w*i+j;
        if((i+j)%2) add_edge(u, T, r[i][j]);
        else add_edge(S, u, r[i][j]);
        rep(k,4)
        {
            int nx = j+dx[k], ny = i+dy[k];
            if(IN(nx,ny))
            {
                int v = w*ny+nx;
                if((i+j)%2) add_edge(v, u, M);
                else add_edge(u, v, M);
            }
        }
    }

    return sr-max_flow(S,T);
}

int main()
{
    int CASE;
    scanf(" %d", &CASE);
    rep(c,CASE) printf("Case %d: %d\n", c+1, solve());
    return 0;
}
