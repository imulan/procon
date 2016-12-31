#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<int> G[20];

vector<int> tlist;
vector<bool> vis;

void dfs(int v)
{
    if(vis[v]) return;
    vis[v]=true;
    rep(i,G[v].size()) dfs(G[v][i]);
    tlist.pb(v);
}

void tsort(int n)
{
    vis = vector<bool>(n,false);
    rep(i,n) dfs(i);
    reverse(all(tlist));
}

int main()
{
    int m,n;
    cin >>m >>n;

    rep(i,n)
    {
        int x,y;
        cin >>x >>y;
        --x;--y;
        if(x!=1) G[x].pb(y);
    }

    tsort(m);
    rep(i,m) cout << tlist[i]+1 << endl;
    return 0;
}
