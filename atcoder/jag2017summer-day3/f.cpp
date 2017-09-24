#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int N = 100000;
const int INF = 19191919;
int n,m;
vector<int> G[N];
int d[N][2];

int solve()
{
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    queue<int> que;
    que.push(0);
    vector<int> dist(n,INF);
    dist[0]=0;
    while(!que.empty())
    {
        int v = que.front(); que.pop();
        for(int nx:G[v])
        {
            if(dist[nx]>dist[v]+1)
            {
                dist[nx] = dist[v]+1;
                que.push(nx);
            }
        }
    }

    bool ok = false;
    rep(i,n)
    {
        for(int nx:G[i])
        {
            int diff = abs(dist[i]-dist[nx]);
            if(diff%2==0) ok = true;
        }
    }

    if(!ok) return -1;

    fill(d[0],d[N],INF);
    queue<pi> Q;
    Q.push({0,0});
    d[0][0] = 0;
    while(!Q.empty())
    {
        pi now = Q.front();
        Q.pop();
        int v = now.fi;
        for(int nx:G[v])
        {
            int nd = d[v][now.se]+1;
            if(d[nx][nd%2] > nd)
            {
                d[nx][nd%2] = nd;
                Q.push({nx,nd%2});
            }
        }
    }

    int x[2]={};
    rep(j,2)rep(i,n)
    {
        x[j] = max(x[j],d[i][j]);
    }
    return min(x[0],x[1]);
}

int main()
{
    cout << solve() << endl;
    return 0;
}
