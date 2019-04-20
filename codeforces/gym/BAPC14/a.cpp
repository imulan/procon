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

const int MAX_V = 101010;
const int F_INF = 191919;
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
                level[e.to] = level[v] + 1;
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


void solve(){
    rep(i,MAX_V) G[i].clear();

    int n;
    scanf(" %d", &n);

    int start,people,tl;
    scanf(" %d %d %d", &start, &people, &tl);
    --start;

    int num_goal;
    scanf(" %d", &num_goal);
    vector<bool> goal(n);
    rep(i,num_goal){
        int g;
        scanf(" %d", &g);
        --g;
        goal[g] = true;
    }

    int S = 0, T = (tl+1)*n+1;

    auto ID = [&](int pos, int sec){
        return sec*n + pos + 1;
    };

    add_edge(S, ID(start,0), people);

    rep(i,n){
        rep(j,tl) add_edge(ID(i,j), ID(i,j+1), people);
        if(goal[i]){
            rep(j,tl+1) add_edge(ID(i,j), T, people);
        }
    }

    int m;
    scanf(" %d", &m);
    rep(i,m){
        int a,b,p,t;
        scanf(" %d %d %d %d", &a, &b, &p, &t);
        --a;
        --b;
        for(int j=0; j+t<=tl; ++j){
            add_edge(ID(a,j), ID(b,j+t), p);
        }
    }

    int f = max_flow(S,T);
    printf("%d\n", min(f,people));
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
