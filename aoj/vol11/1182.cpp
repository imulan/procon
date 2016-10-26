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
typedef pair<int,pi> P;

const int INF=123456789;

struct line{int a,b,cost;};
struct edge{int to,cost,company;};

int p[20],q[20][50],r[21][50];

int calc_cost(int dist, int company)
{
    if(p[company]==1) return dist*r[company][0];

    if(dist<q[company][0]) return dist*r[company][0];

    int ret=q[company][0]*r[company][0];
    dist-=q[company][0];
    int idx=1;
    while(idx<p[company]-1)
    {
        int b=q[company][idx]-q[company][idx-1];
        if(dist-b<=0)
        {
            ret+=dist*r[company][idx];
            dist=0;
            break;
        }
        else
        {
            ret+=b*r[company][idx];
            dist-=b;
            ++idx;
        }
    }

    if(dist>0) ret+=dist*r[company][idx];
    return ret;
}

int main()
{
    int n,m,c,s,g;
    while(cin >>n >>m >>c >>s >>g,n)
    {
        --s;
        --g;

        vector<line> L[20];
        // input
        rep(i,m)
        {
            int x,y,dist,company;
            scanf(" %d %d %d %d", &x, &y, &dist, &company);
            --x;
            --y;
            --company;
            L[company].pb(line{x,y,dist});
        }
        rep(i,c) scanf(" %d", &p[i]);
        rep(i,c)
        {
            rep(j,p[i]-1) scanf(" %d", &q[i][j]);
            rep(j,p[i]) scanf(" %d", &r[i][j]);
        }

        vector<edge> G[100];
        rep(i,c)
        {
            int d[100][100];
            // initialize
            fill(d[0],d[100],INF);
            rep(j,n) d[j][j]=0;

            rep(j,L[i].size())
            {
                int A=L[i][j].a, B=L[i][j].b, COST=L[i][j].cost;
                if(d[A][B]>COST) d[A][B]=d[B][A]=COST;
            }

            rep(k,n)rep(x,n)rep(y,n) d[x][y]=min(d[x][y],d[x][k]+d[k][y]);

            rep(x,n)rep(y,x)
            {
                if(d[x][y]<INF)
                {
                    int cost=calc_cost(d[x][y],i);
                    G[x].pb(edge{y,cost,i});
                    G[y].pb(edge{x,cost,i});
                    // printf("(%d, %d) -> %d (dist=%d)\n", x,y,cost,d[x][y]);
                }
            }
        }

        // dijkstra
        priority_queue< P,vector<P>,greater<P> > que;
        int dist[100][20];
        fill(dist[0],dist[100],INF);
        dist[s][0]=0;
        que.push(P(0,pi(s,0)));
        while(!que.empty())
        {
            P now=que.top();
            que.pop();
            pi v=now.se;
            if(dist[v.fi][v.se]<now.fi) continue;
            rep(i,G[v.fi].size())
            {
                edge e=G[v.fi][i];
                if(dist[e.to][e.company]>dist[v.fi][v.se]+e.cost)
                {
                    dist[e.to][e.company]=dist[v.fi][v.se]+e.cost;
                    que.push(P(dist[e.to][e.company],pi(e.to,e.company)));
                }
            }
        }

        int ans=INF;
        rep(i,c) ans=min(ans,dist[g][i]);
        if(ans==INF) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
