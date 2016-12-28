#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
struct edge{ int to,cost; };

const int N=5000, INF=123456789;
vector<int> G[N];

int dist[N][N];
int d[N];
void bfs(int start)
{
    fill(d,d+N,INF);
    d[start]=0;
    queue<int> que;
    que.push(start);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,G[v].size())
        {
            int nx=G[v][i];
            if(d[nx]>d[v]+1)
            {
                d[nx]=d[v]+1;
                que.push(nx);
            }
        }
    }
}

vector<edge> g[N];
int fare[N];
void dijkstra(int start)
{
    fill(fare,fare+N,INF);

    priority_queue<pi,vector<pi>,greater<pi>> que;
    fare[start]=0;
    que.push(pi(0,start));
    while(!que.empty()){
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(fare[v]<p.fi) continue;
        rep(i,g[v].size())
        {
            edge e=g[v][i];
            if(fare[e.to]>fare[v]+e.cost)
            {
                fare[e.to]=fare[v]+e.cost;
                que.push(pi(fare[e.to],e.to));
            }
        }
    }
}

int main()
{
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> c(n),r(n);
    rep(i,n) scanf(" %d %d", &c[i], &r[i]);

    rep(i,k)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    rep(i,n)
    {
        bfs(i);
        rep(j,n)
        {
            if(d[j]<=r[i]) g[i].pb(edge{j,c[i]});
        }
    }

    dijkstra(0);
    printf("%d\n", fare[n-1]);
    return 0;
}
