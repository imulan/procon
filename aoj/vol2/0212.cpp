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

struct edge{int to,cost;};
vector<edge> G[100];

const int INF=123456789;
int dist[11][100];

int main()
{
    int c,n,m,s,d;
    while(cin >>c >>n >>m >>s >>d,c)
    {
        rep(i,100) G[i].clear();

        --s;
        --d;
        rep(i,m)
        {
            int a,b,f;
            scanf(" %d %d %d", &a, &b, &f);
            --a;
            --b;
            G[a].pb(edge{b,f});
            G[b].pb(edge{a,f});
        }

        fill(dist[0],dist[11],INF);
        dist[0][s]=0;
        queue<pi> que;
        que.push(pi(0,s));
        while(!que.empty())
        {
            pi p=que.front(); que.pop();
            int ticket=p.fi;
            int now=p.se;
            rep(i,G[now].size())
            {
                edge e=G[now][i];
                if(dist[ticket][e.to]>dist[ticket][now]+e.cost)
                {
                    dist[ticket][e.to]=dist[ticket][now]+e.cost;
                    que.push(pi(ticket,e.to));
                }
                if(ticket<c)
                {
                    if(dist[ticket+1][e.to]>dist[ticket][now]+e.cost/2)
                    {
                        dist[ticket+1][e.to]=dist[ticket][now]+e.cost/2;
                        que.push(pi(ticket+1,e.to));
                    }
                }
            }
        }

        int ans=INF;
        rep(i,c+1) ans=min(ans,dist[i][d]);
        printf("%d\n", ans);
    }
    return 0;
}
