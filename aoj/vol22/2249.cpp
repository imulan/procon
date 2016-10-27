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

const int N=10000;
const int M=20000;
const int INF=123456789;

struct edge{int to,dist,cost;};
vector<edge> G[N];

int u[M],v[M],d[M],c[M];

int D[N];
int PAR[N],COST[N];

int main()
{
    int n,m;
    while(cin >>n >>m,n)
    {
        rep(i,n) G[i].clear();

        rep(i,m)
        {
            scanf(" %d %d %d %d", &u[i], &v[i], &d[i], &c[i]);
            --u[i];
            --v[i];
            G[u[i]].pb(edge{v[i],d[i],c[i]});
            G[v[i]].pb(edge{u[i],d[i],c[i]});
        }

        // dijkstra
        priority_queue<pi,vector<pi>,greater<pi>> que;
        fill(D,D+N,INF);
        fill(COST,COST+N,INF);
        fill(PAR,PAR+N,-1);
        D[0]=0;
        COST[0]=0;

        que.push(pi(0,0));
        while(!que.empty())
        {
            pi p=que.top();
            que.pop();
            int V=p.se;
            if(D[V]<p.fi) continue;
            rep(i,G[V].size())
            {
                edge e=G[V][i];
                if(D[e.to]>D[V]+e.dist || (D[e.to]==D[V]+e.dist && COST[e.to]>e.cost))
                {
                    D[e.to]=D[V]+e.dist;
                    PAR[e.to]=V;
                    COST[e.to]=e.cost;
                    que.push(pi(D[e.to],e.to));
                }
            }
        }

        int ans=0;
        rep(i,n) ans+=COST[i];
        printf("%d\n", ans);
    }
    return 0;
}
