#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int INF=100000000;

typedef pair<int,int> pi;
typedef pair<int,pi> P;

struct edge{ int to,cost; };

vector<edge> G[100];

int main()
{
    while(1)
    {
        int n,m,l,k,a,h;
        scanf(" %d %d %d %d %d %d", &n, &m ,&l, &k, &a, &h);
        if(n==0) break;

        rep(i,n) G[i].resize(0);

        //冷凍施設があるか
        int cold[100]={0};
        rep(i,l)
        {
            int t;
            scanf(" %d",&t);
            cold[t]=1;
        }

        //辺の構成
        rep(i,k)
        {
            int x,y,z;
            scanf(" %d %d %d", &x, &y, &z);
            G[x].pb(edge{y,z});
            G[y].pb(edge{x,z});
        }

        int d[100][101];
        fill(d[0],d[100],INF);
        d[a][m]=0;

        //dijkstra
        priority_queue<P,vector<P>,greater<P>> que;
        que.push(P(0,pi(a,m)));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            int v=p.se.fi;
            int r=p.se.se;
            if(d[v][r]<p.fi) continue;
            rep(i,G[v].size())
            {
                edge e=G[v][i];
                if(r-e.cost>=0 && d[e.to][r-e.cost]>d[v][r]+e.cost)
                {
                    d[e.to][r-e.cost]=d[v][r]+e.cost;
                    que.push(P(d[e.to][r-e.cost],pi(e.to,r-e.cost)));
                    if(cold[e.to])
                    {
                        for(int j=1; r-e.cost+j<=m; ++j)
                        {
                            if(d[e.to][r-e.cost+j]>d[e.to][r-e.cost]+j)
                            {
                                d[e.to][r-e.cost+j]=d[e.to][r-e.cost]+j;
                                que.push(P(d[e.to][r-e.cost+j],pi(e.to,r-e.cost+j)));
                            }
                        }
                    }
                }
            }

        }

        int ans=INF;
        rep(i,m+1) ans=min(ans,d[h][i]);

        if(ans==INF) printf("Help!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
