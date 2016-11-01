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

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<int> p(n),t(n);
        rep(i,n) scanf(" %d %d", &p[i],&t[i]);

        int dp[41][4];
        fill(dp[0],dp[41],INF);
        dp[0][0]=0;
        if(p[0]<=t[0]) dp[1][1]=p[0];

        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<=3; ++j)
            {
                if(p[i-1]*(j+1)+p[i]<=t[i]-t[i-1])
                dp[i+1][1]=min(dp[i+1][1],dp[i][j]+p[i]+p[i-1]);
            }

            for(int j=2; j<=3; ++j)
            {
                if(abs(p[i]-p[i-1])*j<=t[i]-t[i-1])
                dp[i+1][j]=min(dp[i+1][j],dp[i][j-1]+abs(p[i]-p[i-1]));
            }
        }

        int ans=INF;
        rep(i,4) ans=min(ans,dp[n][i]+p[n-1]);
        if(ans<INF) printf("OK %d\n", ans);
        else
        {
            rep(i,n)
            {
                bool check=false;
                rep(j,4) if(dp[i+1][j]<INF) check=true;
                if(!check)
                {
                    ans=i+1;
                    break;
                }
            }
            printf("NG %d\n", ans);
        }
    }
    return 0;
}
