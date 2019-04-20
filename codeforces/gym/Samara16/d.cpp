#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

struct edge{ int to,cap,rev; };

const int MAX_V = 5005;
const int F_INF = 20000000;
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
            if(e.cap>0 && level[e.to] < 0){
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
        if(e.cap>0 && level[v] < level[e.to]){
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
        if(level[t] < 0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dinic_dfs(s,t,F_INF))>0 ) flow += f;
    }
}

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int main(){
    int h,w,r,c;
    cin >>h >>w >>r >>c;
    --r;
    --c;

    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    auto getu = [&](int y, int x){
        return 2*(y*w+x);
    };

    int S = 2*h*w, T = S+1;
    rep(i,h)rep(j,w){
        int u = getu(i,j), v = u+1;
        add_edge(u,v,a[i][j]);

        rep(d,4){
            int ny = i+dy[d], nx = j+dx[d];
            if(!IN(ny,nx)) continue;

            int ID = getu(ny,nx);
            add_edge(v,ID,F_INF);
        }

        if(i==0 || i==h-1 || j==0 || j==w-1) add_edge(v,T,F_INF);
    }

    add_edge(S, getu(r,c)+1, F_INF);

    int f = max_flow(S,T);
    vector<string> s(h,string(w,'.'));

    vector<bool> vis(T+1);
    vis[S] = true;
    queue<int> que;
    que.push(S);
    while(!que.empty()){
        int v = que.front();
        que.pop();
//        dbg(v);
        for(const auto &e:G[v]){
            if(e.cap>0 && !vis[e.to]){
                vis[e.to] = true;
                que.push(e.to);
            }
        }
    }

    int A = 0;
    rep(i,h)rep(j,w){
        int u = getu(i,j), v = u+1;
        if(vis[u] && !vis[v]){
            s[i][j] = 'X';
            A += a[i][j];
        }
    }

//    dbg(A);
    if(A<f) assert(false);
    if(A>f) while(1){};

    cout << f << endl;
    rep(i,h) cout << s[i] << endl;
    return 0;
}