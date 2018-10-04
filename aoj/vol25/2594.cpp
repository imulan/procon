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

const int MAX_V = 1000; // TODO:initialize
const int F_INF = 1234567; // TODO:initialize
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


bool vs[MAX_V],vt[MAX_V];
void dfs_s(int x){
    vs[x] = true;
    for(const auto &e:G[x]){
        if(e.cap>0 && !vs[e.to]) dfs_s(e.to);
    }
}
void dfs_t(int x){
    vt[x] = true;
    for(const auto &e:G[x]){
        if(e.cap==0 && !vt[e.to]) dfs_t(e.to);
    }
}

int main(){
    int n,m,s,t;
    while(scanf(" %d %d %d %d", &n, &m, &s, &t),n){
        rep(i,MAX_V) G[i].clear();
        fill(vs,vs+MAX_V,false);
        fill(vt,vt+MAX_V,false);

        --s;
        --t;

        vector<int> a(m),b(m);
        rep(i,m){
            scanf(" %d %d", &a[i], &b[i]);
            --a[i];
            --b[i];
            add_edge(a[i],b[i],1);
        }

        int f = max_flow(s,t);

        dfs_s(s);
        dfs_t(t);

        int num = 0;
        rep(i,m){
            if(vs[b[i]] && vt[a[i]]) ++num;
        }
        if(num) ++f;

        printf("%d %d\n", f,num);
    }
    return 0;
}
