#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
vector<int> G[N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<bool> vis(n,false);

    vector<int> x,y;

    int start=0;
    rep(i,n)
    {
        if(G[i].size()>0)
        {
            start = i;
            break;
        }
    }

    int now=start;
    x.pb(now);
    vis[now]=true;
    while(1)
    {
        int tmp=now;
        rep(i,G[now].size())
        {
            int nx=G[now][i];
            if(!vis[nx])
            {
                vis[nx]=true;
                now=nx;
                x.pb(now);
            }
        }

        if(now==tmp) break;
    }

    now=start;
    while(1)
    {
        int tmp=now;
        rep(i,G[now].size())
        {
            int nx=G[now][i];
            if(!vis[nx])
            {
                vis[nx]=true;
                now=nx;
                y.pb(now);
            }
        }

        if(now==tmp) break;
    }

    // printf(" X= %d Y= %d\n", x.size(),y.size());

    reverse(all(y));
    rep(i,x.size()) y.pb(x[i]);

    printf("%d\n", y.size());
    rep(i,y.size())
    {
        if(i) printf(" ");
        printf("%d", y[i]+1);
    }
    printf("\n");
    return 0;
}
