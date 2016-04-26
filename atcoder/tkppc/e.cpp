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

const ll INF=10000000000000000;

//(to,cost)
typedef pair<int,ll> pi;
//Graph
vector<pi> G[100000];

int main()
{
    int n;
    cin >>n;
    rep(i,n-1)
    {
        int a,b;
        ll c;
        scanf(" %d %d %lld", &a, &b, &c);
        --a;
        --b;
        G[a].pb(pi(b,c));
        G[b].pb(pi(a,c));
    }
    
    //0-BFS
    ll dist[100000];
    fill(dist,dist+n,INF);
    dist[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,G[v].size())
        {
            pi nx=G[v][i];
            if(dist[nx.fi]>dist[v]+nx.se)
            {
                dist[nx.fi]=dist[v]+nx.se;
                que.push(nx.fi);
            }
        }
    }

    //0から最も遠い頂点xを探す
    int x=0;
    ll d=0;
    rep(i,n)
    {
        if(dist[i]>d)
        {
            x=i;
            d=dist[i];
        }
    }

    //x-BFS
    ll d1[100000];
    fill(d1,d1+n,INF);
    d1[x]=0;
    que.push(x);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,G[v].size())
        {
            pi nx=G[v][i];
            if(d1[nx.fi]>d1[v]+nx.se)
            {
                d1[nx.fi]=d1[v]+nx.se;
                que.push(nx.fi);
            }
        }
    }

    //xから最も遠い頂点yを探す
    int y=0;
    d=0;
    rep(i,n)
    {
        if(d1[i]>d)
        {
            y=i;
            d=d1[i];
        }
    }

    //y-BFS
    ll d2[100000];
    fill(d2,d2+n,INF);
    d2[y]=0;
    que.push(y);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,G[v].size())
        {
            pi nx=G[v][i];
            if(d2[nx.fi]>d2[v]+nx.se)
            {
                d2[nx.fi]=d2[v]+nx.se;
                que.push(nx.fi);
            }
        }
    }

    //printf("x,y= %d, %d\n",x,y);
    rep(i,n)
    {
        int ans=x;
        if(d1[i]<d2[i]) ans=y;
        else if(d1[i]==d2[i]) ans=min(x,y);
        cout << ans+1 << endl;
    }

    return 0;
}
