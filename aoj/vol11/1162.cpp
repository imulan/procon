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

const double INF=1e9;
const double eps=1e-6;

typedef pair<int,int> pi;
typedef pair<pi,int> P;

struct edge{int to,d,c;};
vector<edge> G[30];

int main()
{
    int n,m;
    while(cin >>n >>m,n)
    {
        rep(i,30) G[i].clear();

        int s,g;
        cin >>s >>g;
        --s;
        --g;

        rep(i,m)
        {
            int x,y,dist,cst;
            cin >>x >>y >>dist >>cst;
            --x;
            --y;
            G[x].pb(edge{y,dist,cst});
            G[y].pb(edge{x,dist,cst});
        }

        double t[30][31][30];
        rep(i,30)rep(j,31)rep(k,30) t[i][j][k]=INF;

        t[s][1][s]=0;

        queue<P> que;
        rep(i,G[s].size())
        {
            edge e=G[s][i];
            t[e.to][1][s]=(double)e.d;
            que.push(P(pi(e.to,1),s));
            //printf("push %d\n", e.to+1);
        }
        while(!que.empty())
        {
            P p=que.front();
            que.pop();

            pi now=p.fi;
            int par=p.se;

            //printf("now %d, speed %d, par %d\n", now.fi,now.se,par);

            rep(i,G[now.fi].size())
            {
                edge e=G[now.fi][i];
                int nx=e.to;
                if(nx==par) continue;

                for(int dv=-1; dv<=1; ++dv)
                {
                    int nv=now.se+dv;
                    if(1<=nv && nv<=e.c)
                    {
                        double add=(double)e.d/nv;
                        if(t[nx][nv][now.fi]>t[now.fi][now.se][par]+add)
                        {
                            t[nx][nv][now.fi]=t[now.fi][now.se][par]+add;
                            que.push(P(pi(nx,nv),now.fi));
                        }
                    }
                }
            }
        }

        double ans=INF;
        rep(i,n) ans=min(t[g][1][i],ans);

        if(fabs(ans-INF)<eps) printf("unreachable\n");
        else printf("%.10lf\n", ans);
    }
    return 0;
}
