#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int ans=0;

int state[200]={0};
vector<int> G[200];

void dfs(int v)
{
    // visiting
    state[v]=2;

    rep(i,G[v].size())
    {
        int to=G[v][i];
        if(state[to]==0) dfs(to);
        else if(state[to]==2) ans=1;
    }

    // finish
    state[v]=1;
}

int main()
{
    int n;
    scanf(" %d", &n);
    rep(i,n)
    {
        int u,d;
        char s[10];
        scanf(" %d %s %d", &u, s, &d);
        --u;
        --d;
        d+=100;

        if(s[0]=='l') G[d].pb(u);
        else G[u].pb(d);
    }

    rep(i,200)
    {
        if(state[i]==0) dfs(i);
    }

    printf("%d\n", ans);
    return 0;
}
