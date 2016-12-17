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

const int N=100000;
const int INF=1010101010;

struct edge{ int to,cost; };

int n,m;

vector<edge> G[N],rG[N];
int d[N],rd[N];

int vis[N];
vector<int> vlist;

void dfs(int v)
{
    if(vis[v]) return;

    vis[v]=1;
    rep(i,G[v].size())
    {
        edge e=G[v][i];
        dfs(e.to);
    }
    vlist.pb(v);
}

void tsort()
{
    fill(vis,vis+N,0);
    rep(i,n) dfs(i);
}


int main()
{
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        G[a].pb(edge{b,c});
        rG[b].pb(edge{a,c});
    }

    tsort();
    int V=vlist.size();

    fill(d,d+N,0);
    for(int i=V-1; i>=0; --i)
    {
        int v=vlist[i];
        rep(j,G[v].size())
        {
            edge e=G[v][j];
            d[e.to]=max(d[e.to], d[v]+e.cost);
        }
    }

    fill(rd,rd+N,0);
    rep(i,V)
    {
        int v=vlist[i];
        rep(j,rG[v].size())
        {
            edge e=rG[v][j];
            rd[e.to]=max(rd[e.to], rd[v]+e.cost);
        }

    }

    // rep(i,n) printf("%d: d = %d, rd = %d\n", i,d[i],d[n-1]-rd[i]);

    int ct=0;
    rep(i,n) ct+=(d[i]==d[n-1]-rd[i]);

    printf("%d %d/%d\n", d[n-1], n-ct, n);
    return 0;
}
