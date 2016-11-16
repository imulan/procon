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
const int INF=123456789;

vector<edge> G[100];
int d[100][3];

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n)
    {
        rep(i,100) G[i].clear();
        fill(d[0],d[100],INF);

        rep(i,m)
        {
            int a,b,c;
            scanf(" %d %d %d", &a, &b, &c);
            --a; --b;
            G[a].pb(edge{b,c});
            G[b].pb(edge{a,c});
        }

        queue<pi> que;
        que.push(pi(0,0));
        d[0][0]=0;
        while(!que.empty())
        {
            pi now=que.front(); que.pop();
            int v=now.fi;
            int st=now.se;

            if(st==1)
            {
                rep(i,G[v].size())
                {
                    edge e=G[v][i];
                    if(d[e.to][2]>d[v][st])
                    {
                        d[e.to][2]=d[v][st];
                        que.push(pi(e.to,2));
                    }
                }
            }
            else
            {
                rep(i,G[v].size())
                {
                    edge e=G[v][i];
                    if(d[e.to][st]>d[v][st]+e.cost)
                    {
                        d[e.to][st]=d[v][st]+e.cost;
                        que.push(pi(e.to,st));
                    }
                }

                if(st==0)
                {
                    rep(i,G[v].size())
                    {
                        edge e=G[v][i];
                        if(d[e.to][1]>d[v][st])
                        {
                            d[e.to][1]=d[v][st];
                            que.push(pi(e.to,1));
                        }
                    }

                }
            }
        }

        printf("%d\n", min(d[n-1][0],d[n-1][2]));
    }
    return 0;
}
