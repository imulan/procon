#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct edge{int to,cost,id;};

vector<edge> G[100];
int C[100][100]={0};

int main()
{
    int n,m,k;
    cin >>n >>m >>k;
    rep(i,m)
    {
        int f,t,c;
        cin >>f >>t >>c;
        --f;
        --t;
        G[f].pb(edge{t,c,i});
        G[t].pb(edge{f,c,i});
        C[f][t]=C[t][f]=c;
    }

    int g=0;

    //閉路に含まれない辺,含まれる辺
    vector<int> x,y;

    vector<bool> vis(n);
    vector<bool> use(m);
    vector<int> par(n,-1);
    rep(i,n)
    {
        if(vis[i]) continue;
        ++g;
        vis[i]=true;
        par[i]=i;

        int viscount=1;
        int va=-1, vb=-1;
        vector<int> cost, dist(n,0);
        queue<int> que;
        que.push(i);
        while(!que.empty())
        {
            int v=que.front();
            que.pop();
            rep(j,G[v].size())
            {
                edge e=G[v][j];
                int nx=e.to;
                if(!use[e.id])
                {
                    use[e.id]=true;
                    cost.pb(e.cost);
                    if(!vis[nx])
                    {
                        vis[nx]=true;
                        que.push(nx);
                        dist[nx]=dist[v]+1;
                        par[nx]=v;
                        ++viscount;
                    }
                    else
                    {
                        va=v;
                        vb=nx;
                        y.pb(e.cost);
                    }
                }
            }
        }

        int COST=cost.size();
        if(viscount==COST)
        {
            //閉路あり
            if(dist[va]>dist[vb])
            {
                while(dist[va]>dist[vb])
                {
                    y.pb(C[va][par[va]]);
                    va=par[va];
                }
            }
            if(dist[va]<dist[vb])
            {
                while(dist[va]<dist[vb])
                {
                    y.pb(C[vb][par[vb]]);
                    vb=par[vb];
                }
            }

            while(va!=vb)
            {
                y.pb(C[va][par[va]]);
                y.pb(C[vb][par[vb]]);
                va=par[va];
                vb=par[vb];
            }

            sort(all(cost));
            sort(all(y));
            int yidx=0;
            rep(cidx,COST)
            {
                if(cost[cidx]==y[yidx]) ++yidx;
                else x.pb(cost[cidx]);
            }
        }
        else for(auto &c:cost) x.pb(c);
    }

    sort(all(x));
    sort(all(y));

    // printf("X,Y %d, %d\n", x.size(), y.size());

    int ans=0;
    if(g<k)
    {
        ans=123456789;
        if(k-g<=x.size())
        {
            int tmp=0;
            rep(i,k-g) tmp+=x[i];
            ans=min(ans,tmp);
        }

        if(y.size()>=3)
        {
            int tmp=y[0]+y[1];

            vector<int> z(x);
            for(int i=2; i<y.size(); ++i) z.pb(y[i]);
            sort(all(z));
            rep(i,k-g-1) tmp+=z[i];

            ans=min(ans,tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
