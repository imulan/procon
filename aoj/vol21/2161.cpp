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

struct edge{int to,cap,rev;};

const int MAX_V = 222;
const int F_INF = 19191919;
vector<edge> G[MAX_V];
int lv[MAX_V],it[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
}

void dinic_bfs(int s){
    memset(lv,-1,sizeof(lv));
    queue<int> que;
    lv[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 && lv[e.to]<0){
                lv[e.to] = lv[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=it[v]; i<G[v].size(); ++i){
        edge &e = G[v][i];
        if(e.cap>0 && lv[v]<lv[e.to]){
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
        if(lv[t]<0) return flow;
        memset(it,0,sizeof(it));
        int f;
        while((f=dinic_dfs(s,t,F_INF))>0) flow+=f;
    }
}

struct Point{ int x,y,v; };

inline double dist(const Point &p, const Point &q)
{
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

using pi = pair<int,int>;
using pd = pair<double,pi>;

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n)
    {
        rep(i,MAX_V) G[i].clear();
        int S = n+m, T = S+1;

        vector<Point> t(n),b(m);
        rep(i,n) scanf(" %d %d %d", &t[i].x, &t[i].y, &t[i].v);
        rep(i,m) scanf(" %d %d", &b[i].x, &b[i].y);

        vector<pd> e;
        rep(i,n)rep(j,m) e.pb({dist(t[i],b[j])/t[i].v,pi(i,j)});
        sort(all(e));

        rep(i,n) add_edge(S,i,1);
        rep(i,m) add_edge(n+i,T,1);

        int idx = 0;
        int f = 0;
        int E = e.size();
        while(idx<E)
        {
            int u = e[idx].se.fi, v = n+e[idx].se.se;
            add_edge(u,v,1);
            f += max_flow(S,T);
            if(f==m) break;
            ++idx;
        }

        assert(idx<E);
        printf("%.10f\n", e[idx].fi);
    }
    return 0;
}
