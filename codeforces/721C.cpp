#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1000000002;

typedef pair<int,int> pi;

struct edge{int to,cost;};
vector<edge> G[5000];

int n,m,T;

int dp[5005][5005];
int nx[5005][5005];

int dfs(int now, int num)
{
    if(dp[now][num]>=0) return dp[now][num];

    int ret=INF;
    if(num==1)
    {
        if(now==n-1) return 0;
        return INF;
    }
    else
    {
        rep(i,G[now].size())
        {
            edge e=G[now][i];
            // printf(" call %d, %d\n", e.to, num);
            int v=dfs(e.to,num-1);

            if(ret>v+e.cost && v+e.cost<=T)
            {
                ret=v+e.cost;
                nx[now][num]=e.to;
                // printf("nx[%d][%d]=%d\n", now,num,e.to);
            }
        }

    }

    return dp[now][num]=min(INF,ret);
}

int main()
{
    scanf(" %d %d %d", &n, &m, &T);
    rep(i,m)
    {
        int u,v,t;
        scanf(" %d %d %d", &u, &v, &t);
        --u;
        --v;
        G[u].pb(edge{v,t});
    }

    memset(dp,-1,sizeof(dp));
    memset(nx,-1,sizeof(nx));

    int ans=n-1;
    for(int i=n; i>=2; --i)
    {
        int val=dfs(0,i);
        if(val>=0 && val<=T)
        {
            ans=i;
            break;
        }
    }

    int cur=0;
    int ct=ans;
    vector<int> a;
    while(1)
    {
        // printf("cur,ct = %d , %d\n", cur,ct);
        a.pb(cur);
        if(cur==n-1) break;

        cur=nx[cur][ct];
        --ct;
    }
    // reverse(all(a));

    printf("%d\n", ans);
    rep(i,a.size())
    {
        if(i) printf(" ");
        printf("%d", a[i]+1);
    }
    printf("\n");
    return 0;
}
