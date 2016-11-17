#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

const int INF=12345678;
int dp[10][1100];

int main()
{
    int n,m;
    int a[10],b[10],c[10],p[10],r[10];

    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        scanf(" %d %d %d %d %d", &a[i], &b[i], &c[i], &p[i], &r[i]);
        --a[i]; --b[i]; --c[i];
    }

    fill(dp[0],dp[10],INF);
    dp[0][1]=0;
    queue<pi> que;
    que.push(pi(0,1));
    while(!que.empty())
    {
        pi now=que.front(); que.pop();
        int v=now.fi;
        int mask=now.se;
        rep(i,m)
        {
            if(a[i]==v)
            {
                int to=b[i];
                int cost=r[i];
                if(mask>>c[i]&1) cost=p[i];

                int nm = mask|(1<<to);
                if(dp[to][nm] > dp[v][mask]+cost)
                {
                    dp[to][nm] = dp[v][mask]+cost;
                    que.push(pi(to,nm));
                }
            }
        }
    }

    int ans=INF;
    rep(mask,1<<n) ans=min(ans,dp[n-1][mask]);
    if(ans==INF) printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}
