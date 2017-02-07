#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int V=200000;
vector<int> G[V];

int n,k;
int u[V]={};

int s[V];
int dfs(int now, int p)
{
    if(s[now]>=0) return s[now];

    int ret=u[now];

    rep(i,G[now].size())
    {
        int nx=G[now][i];
        if(nx == p) continue;
        ret += dfs(nx,now);
    }

    return s[now]=ret;
}

int main()
{
    scanf(" %d %d", &n, &k);
    rep(i,2*k)
    {
        int a;
        scanf(" %d", &a);
        --a;
        u[a]=1;
    }
    rep(i,n-1)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    memset(s,-1,sizeof(s));
    dfs(0,0);

    ll ans=0;
    rep(i,n) ans += min(s[i],2*k-s[i]);
    cout << ans << endl;
    return 0;
}
