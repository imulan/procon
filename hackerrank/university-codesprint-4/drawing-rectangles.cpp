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

const int MAX_V = 600006; // TODO:initialize
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

const int N = 300001;

bool vis[MAX_V] = {};
void zdfs(int now){
    vis[now] = true;
    for(const auto &e:G[now]){
        if(e.cap==1 && !vis[e.to]) zdfs(e.to);
    }
}

using pi = pair<int,int>;

const int B =  25;
const int FF = 300000/B;
set<pi> filled;
set<int> Y[N];

int main(){
    int n;
    scanf(" %d", &n);

    int S = 2*N+1, T = S+1;
    rep(i,N){
        add_edge(S,i,1);
        add_edge(N+i,T,1);
    }

    rep(i,n){
        int x1,y1,x2,y2;
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);

        int lx = x1/B, rx = x2/B;
        int ly = y1/B, ry = y2/B;

        for(int x=lx+1; x<rx; ++x)for(int y=ly+1; y<ry; ++y){
            filled.insert({y,x});
        }

        if(y2-y1 > x2-x1){
            if(ly==ry){
                for(int y=y1; y<=y2; ++y){
                    for(int x=x1; x<=x2; ++x) Y[y].insert(x);
                }
            }
            else{
                for(int y=y1; y<B*(ly+1); ++y){
                    for(int x=x1; x<=x2; ++x) Y[y].insert(x);
                }
                for(int y=B*ry; y<=y2; ++y){
                    for(int x=x1; x<=x2; ++x) Y[y].insert(x);
                }
            }
        }
        else{
            if(lx==rx){
                for(int y=y1; y<=y2; ++y){
                    for(int x=x1; x<=x2; ++x) Y[y].insert(x);
                }
            }
            else{
                for(int y=y1; y<=y2; ++y){
                    for(int x=x1; x<B*(lx+1); ++x) Y[y].insert(x);
                    for(int x=B*rx; x<=x2; ++x) Y[y].insert(x);
                }
            }
        }
    }

    for(pi p:filled){
        int i=p.fi, j=p.se;
        for(int y=B*i; y<B*(i+1); ++y)for(int x=B*j; x<B*(j+1); ++x){
            Y[y].insert(x);
        }
    }

    rep(y,N){
        for(int x:Y[y]){
        printf(" (%d %d)\n", x,y);
          add_edge(x,N+y,1);
        }
    }

    int f = max_flow(S,T);
    printf("%d\n",f);

    zdfs(S);

    vector<int> X,Y;
    rep(i,N){
        if(!vis[i]) X.pb(i);
        if(vis[N+i]) Y.pb(i);
    }

    int xx = X.size();
    printf("%d\n", xx);
    rep(i,xx){
        printf("%d", X[i]);
        if(i!=xx-1) printf(" ");
    }
    printf("\n");

    int yy = Y.size();
    printf("%d\n", yy);
    rep(i,yy){
        printf("%d", Y[i]);
        if(i!=yy-1) printf(" ");
    }
    printf("\n");
    return 0;
}
