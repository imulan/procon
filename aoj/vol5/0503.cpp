#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m;
int pw[16];

const int N=14350000;
const int INF=12345679;

int dp[N];

int main()
{
    pw[0]=1;
    for(int i=1; i<16; ++i) pw[i] = pw[i-1]*3;

    while(scanf(" %d %d", &n, &m),n)
    {
        int start = 0;
        rep(i,3)
        {
            int a;
            scanf(" %d", &a);
            while(a--)
            {
                int c;
                scanf(" %d", &c);
                --c;
                start += i*pw[c];
            }
        }

        fill(dp,dp+N,INF);
        dp[start]=0;
        queue<int> que;
        que.push(start);
        while(!que.empty())
        {
            int s = que.front();
            que.pop();

            int pos[15];
            vector<int> big(3,-1);
            int t=s;
            rep(i,n)
            {
                pos[i]=t%3;
                t/=3;

                big[pos[i]]=i;
            }

            int ns;
            if(big[0]>=0)
            {
                // 0->1
                if(big[0]>big[1])
                {
                    ns = s+pw[big[0]];
                    if(dp[ns]>dp[s]+1)
                    {
                        dp[ns] = dp[s]+1;
                        que.push(ns);
                    }
                }
            }

            if(big[1]>=0)
            {
                // 1->0
                if(big[1]>big[0])
                {
                    ns = s-pw[big[1]];
                    if(dp[ns]>dp[s]+1)
                    {
                        dp[ns] = dp[s]+1;
                        que.push(ns);
                    }
                }

                // 1->2
                if(big[1]>big[2])
                {
                    ns = s+pw[big[1]];
                    if(dp[ns]>dp[s]+1)
                    {
                        dp[ns] = dp[s]+1;
                        que.push(ns);
                    }
                }

            }

            if(big[2]>=0)
            {
                // 2->1
                if(big[2]>big[1])
                {
                    ns = s-pw[big[2]];
                    if(dp[ns]>dp[s]+1)
                    {
                        dp[ns]=dp[s]+1;
                        que.push(ns);
                    }
                }
            }
        }

        int ans = min(dp[0],dp[pw[n]-1]);
        if(ans > m) ans=-1;
        printf("%d\n", ans);
    }

    return 0;
}
