#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct state{ int r,s,jump; };

const ll INF=12345678901234LL;
// i行目, j番目の石, k回一行飛ばしジャンプ使用
ll dp[150][10][150];

int k[150];
int x[150][10], d[150][10];

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n)
    {
        rep(i,n)
        {
            scanf(" %d", &k[i]);
            rep(j,k[i]) scanf(" %d %d", &x[i][j], &d[i][j]);
        }

        fill(dp[0][0],dp[150][0],INF);

        queue<state> que;
        // 0行目
        rep(i,k[0])
        {
            que.push(state{0,i,0});
            dp[0][i][0]=0;
        }
        // 1行目
        if(m>0)
        {
            rep(i,k[1])
            {
                que.push(state{1,i,1});
                dp[1][i][1]=0;
            }
        }

        ll ans=INF;

        while(!que.empty())
        {
            state now=que.front();
            que.pop();

            if(now.r == n-1 || (now.r == n-2 && now.jump < m))
            {
                ans = min(ans, dp[now.r][now.s][now.jump]);
                continue;
            }

            // 普通のジャンプ
            rep(i,k[now.r+1])
            {
                ll add=(d[now.r][now.s]+d[now.r+1][i])*abs(x[now.r][now.s]-x[now.r+1][i]);

                if(dp[now.r+1][i][now.jump] > dp[now.r][now.s][now.jump]+add)
                {
                    dp[now.r+1][i][now.jump] = dp[now.r][now.s][now.jump]+add;
                    que.push(state{now.r+1,i,now.jump});
                }
            }

            // 一行飛ばしのジャンプ
            if(now.jump<m)
            {
                rep(i,k[now.r+2])
                {
                    ll add=(d[now.r][now.s]+d[now.r+2][i])*abs(x[now.r][now.s]-x[now.r+2][i]);

                    if(dp[now.r+2][i][now.jump+1] > dp[now.r][now.s][now.jump]+add)
                    {
                        dp[now.r+2][i][now.jump+1] = dp[now.r][now.s][now.jump]+add;
                        que.push(state{now.r+2,i,now.jump+1});
                    }
                }
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
