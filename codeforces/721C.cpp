#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;

typedef pair<int,int> pi;

struct edge{int to,cost;};
vector<edge> G[5000],invG[5000];

map<pi,int> dp;

int main()
{
    int n,m,T;
    scanf(" %d %d %d", &n, &m, &T);
    rep(i,m)
    {
        int u,v,t;
        scanf(" %d %d %d", &u, &v, &t);
        --u;
        --v;
        G[u].pb(edge{v,t});
        invG[v].pb(edge{u,t});
    }

    dp[pi(0,1)]=0;
    queue<pi> que;
    que.push(pi(0,1));
    while(!que.empty())
    {
        pi now=que.front();
        que.pop();
        int v=now.fi;
        int num=now.se;
        // printf(" now %d\n", v);

        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(dp.find(pi(e.to,num+1))==dp.end() || dp[pi(e.to,num+1)]>dp[now]+e.cost)
            {
                dp[pi(e.to,num+1)]=dp[now]+e.cost;
                que.push(pi(e.to,num+1));
                // printf("update %d\n", dp[pi(e.to,num+1)]);

            }
        }
    }

    int ans=0;
    for(int i=n; i>=2; --i)
    {
        if(dp.find(pi(n-1,i))!=dp.end() && dp[pi(n-1,i)]<=T)
        {
            ans=i;
            // printf("dp %d = %d\n", i,dp[pi(n-1,i)]);
            break;
        }
    }

    int cur=n-1;
    int ct=ans;
    vector<int> a;
    while(1)
    {
        // printf("cur =%d\n", cur);
        a.pb(cur);
        if(cur==0) break;

        rep(i,invG[cur].size())
        {
            edge e=invG[cur][i];
            // printf(" ? %d, %d -> %d\n", e.to, dp[pi(cur,ct)], dp[pi(e.to,ct-1)]);
            if(dp[pi(cur,ct)]-e.cost == dp[pi(e.to,ct-1)])
            {
                cur=e.to;
                --ct;
                break;
            }
        }
    }
    reverse(all(a));

    printf("%d\n", ans);
    rep(i,ans)
    {
        if(i) printf(" ");
        printf("%d", a[i]+1);
    }
    printf("\n");
    return 0;
}
