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

const double INF=1e10;
const double EPS=1e-6;

int main()
{
    int n,m,p,a,b;
    while(cin >>n >>m >>p >>a >>b,n)
    {
        --a;
        --b;

        vector<int> t(n);
        rep(i,n) scanf(" %d", &t[i]);

        vector<vector<edge>> G(m);
        rep(i,p)
        {
            int x,y,z;
            scanf(" %d %d %d", &x, &y, &z);
            --x;
            --y;
            G[x].pb(edge{y,z});
            G[y].pb(edge{x,z});
        }

        // 都市iに馬車券使用状況jで用達するのに要する時間の最小値
        double d[30][257];
        fill(d[0],d[30],INF);
        d[a][0]=0;

        queue<pi> que;
        que.push(pi(a,0));
        while(!que.empty())
        {
            pi v=que.front();
            que.pop();

            int now=v.fi, state=v.se;

            rep(i,G[now].size())
            {
                edge e=G[now][i];
                rep(j,n)
                {
                    // もう既に使われた馬車券なのでダメ
                    if(state>>j&1) continue;

                    int nxstate=state+(1<<j);
                    if(d[e.to][nxstate] > d[now][state]+(double)e.cost/t[j])
                    {
                        d[e.to][nxstate] = d[now][state]+(double)e.cost/t[j];
                        que.push(pi(e.to,nxstate));
                    }
                }
            }
        }

        double ans=INF;
        rep(i,1<<n) ans=min(ans,d[b][i]);

        if(fabs(ans-INF)<EPS) printf("Impossible\n");
        else printf("%.10lf\n", ans);
    }
    return 0;
}
