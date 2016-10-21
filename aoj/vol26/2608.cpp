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

const int N=100000, M=300000;
const int INF=12345678;

int d[2][N];
vector<int> G[N];

int d_ct=0;
void dijkstra(int s)
{
    // dijkstra
    priority_queue<pi,vector<pi>,greater<pi>> que;
    fill(d[d_ct],d[d_ct]+N,INF);
    d[d_ct][s]=0;
    que.push(pi(0,s));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d[d_ct][v]<p.fi) continue;
        rep(i,G[v].size())
        {
            int nx=G[v][i];
            if(d[d_ct][nx]>d[d_ct][v]+1)
            {
                d[d_ct][nx]=d[d_ct][v]+1;
                que.push(pi(d[d_ct][nx],nx));
            }
        }
    }
    ++d_ct;
}

int cts[N]={0}, ctt[N]={0};

int main()
{
    int n,m,s,t;
    scanf(" %d %d %d %d", &n, &m, &s, &t);
    --s;
    --t;
    rep(i,m)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    dijkstra(s);
    dijkstra(t);

    rep(i,n) if(d[0][i]<N) ++cts[d[0][i]];
    rep(i,n) if(d[1][i]<N) ++ctt[d[1][i]];

    ll ans=0;
    rep(i,d[0][t]-1) ans+=(ll)cts[i]*ctt[d[0][t]-2-i];
    cout << ans << endl;
    return 0;
}
