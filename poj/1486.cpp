#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 100; // TODO:initialize
const int F_INF = 364364364; // TODO:initialize
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

struct Point
{
    int x,y;
};
struct Rect
{
    int lx,rx,ly,ry;
    bool IN(const Point &p)
    {
        return (lx<p.x && p.x<rx && ly<p.y && p.y<ry);
    }
};

const int N = 100;
int n;
Rect a[N];
Point num[N];

void solve()
{
    // input
    rep(i,n) scanf(" %d %d %d %d", &a[i].lx, &a[i].rx, &a[i].ly, &a[i].ry);
    rep(i,n) scanf(" %d %d", &num[i].x, &num[i].y);

    int S = MAX_V-2, T = MAX_V-1;
    vector<int> match(n,-1);

    rep(i,n)
    {
        int m_ct = 0;
        rep(j,n)
        {
            if(!a[i].IN(num[j])) continue;

            rep(v,MAX_V) G[v].clear();
            rep(v,n) add_edge(S,v,1);
            rep(v,n) add_edge(n+v,T,1);
            rep(k,n)rep(l,n)if(k!=i && l!=j)
            {
                if(a[k].IN(num[l])) add_edge(k,n+l,1);
            }

            if(max_flow(S,T)==n-1)
            {
                match[i]=j;
                ++m_ct;
            }
        }
        if(m_ct>1) match[i]=-1;
    }

    bool flag = false;
    rep(i,n)
    {
        if(match[i]!=-1)
        {
            if(flag) printf(" ");
            printf("(%c,%d)", 'A'+i, match[i]+1);
            flag = true;
        }
    }
    if(!flag) printf("none");
    printf("\n");
}

int main()
{
    int heap = 1;
    while(cin >>n,n)
    {
        printf("Heap %d\n", heap++);
        solve();
        printf("\n");
    }
    return 0;
}
