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

const int MAX_V = 500; // TODO:initialize
const int F_INF = 19191919; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,cap,(int)G[from].size()-1});
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

int n;

void back(int s, int g, int val)
{
    vector<int> par(n,-1);
    queue<int> que;
    par[s]=s;
    que.push(s);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        rep(i,G[v].size())
        {
            int nx = G[v][i].to;
            if(G[v][i].cap==val && G[nx][G[v][i].rev].cap==abs(val-2) && par[nx]==-1)
            {
                que.push(nx);
                par[nx] = v;
            }
        }
    }

    int now = g;
    while(now!=s)
    {
        int nx = par[now];
        rep(i,G[now].size())
        {
            if(G[now][i].to==nx)
            {
                G[now][i].cap = 1;
                G[nx][G[now][i].rev].cap = 1;

                now = nx;
                break;
            }
        }
        assert(now==nx);
    }
}

int main()
{
    int e,q;
    scanf(" %d %d %d", &n, &e, &q);
    rep(i,e)
    {
        int f,t;
        scanf(" %d %d", &f, &t);
        --f;
        --t;
        add_edge(f,t,1);
    }

    int f = max_flow(0,n-1);
    while(q--)
    {
        int m,a,b;
        scanf(" %d %d %d", &m, &a, &b);
        --a;
        --b;
        if(m==1)
        {
            bool found = false;
            rep(i,G[a].size())if(G[a][i].to==b)
            {
                G[a][i].cap = 1;
                G[b][G[a][i].rev].cap = 1;
                assert(G[b][G[a][i].rev].to == a);
                found = true;
                break;
            }

            if(!found) add_edge(a,b,1);
            f += max_flow(0,n-1);
        }
        else
        {
            int id = -1;
            rep(i,G[a].size())
            {
                if(G[a][i].to==b)
                {
                    id = i;
                    int CAP = G[a][i].cap;
                    if(CAP==2)
                    {
                        id = G[a][i].rev;
                        swap(a,b);
                    }
                    break;
                }
            }

            assert(G[b][G[a][id].rev].to == a);
            assert(id!=-1);
            if(G[a][id].cap==0)
            {
                --f;
                back(a,0,2);
                back(b,n-1,0);
            }
            G[a][id].cap = 0;
            G[b][G[a][id].rev].cap = 0;
            f += max_flow(0,n-1);
        }
        printf("%d\n", f);
    }
    return 0;
}
