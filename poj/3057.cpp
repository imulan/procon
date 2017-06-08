#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 11000; // TODO:initialize
const int F_INF = 12345678; // TODO:initialize
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
int d[12][12][12][12];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

void solve()
{
    rep(i,MAX_V) G[i].clear();

    int Y,X;
    cin >>Y >>X;
    vector<string> s(Y);
    rep(i,Y) cin >>s[i];

    vector<pi> people,door;
    rep(i,Y)rep(j,X)
    {
        if(s[i][j]=='.') people.pb(pi(i,j));
        if(s[i][j]=='D') door.pb(pi(i,j));
    }
    // 人,ドアの数
    int P = people.size(), D = door.size();

    // 各ドアからBFSで最短路を計算
    rep(i,12)rep(j,12)rep(k,12)rep(l,12) d[i][j][k][l]=INF;
    #define IN(x,y) (0<=x && x<X && 0<=y && y<Y)
    rep(i,Y)rep(j,X)if(s[i][j]=='D')
    {
        d[i][j][i][j]=0;
        queue<pi> que;
        que.push(pi(i,j));
        while(!que.empty())
        {
            pi p = que.front();
            que.pop();
            rep(dd,4)
            {
                int nx = p.se+dx[dd], ny = p.fi+dy[dd];
                if(IN(nx,ny) && s[ny][nx]=='.' && d[i][j][ny][nx] > d[i][j][p.fi][p.se]+1)
                {
                    d[i][j][ny][nx] = d[i][j][p.fi][p.se]+1;
                    que.push(pi(ny,nx));
                }
            }
        }
    }

    int S=0,T=MAX_V-1;
    rep(i,P) add_edge(S,i+1,1);

    int F=0;
    int t=1;
    while(t<=200)
    {
        rep(j,D) add_edge(P+(t-1)*D+j+1,T,1);

        rep(i,P)rep(j,D)
        {
            if(d[door[j].fi][door[j].se][people[i].fi][people[i].se]<=t) add_edge(i+1,P+(t-1)*D+j+1,1);
        }

        F += max_flow(S,T);
        if(F>=P) break;
        ++t;
    }

    if(F>=P) printf("%d\n", t);
    else printf("impossible\n");
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
