#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=1000000;
double dp[N],dp2[N];

int main()
{
    int n,m,k;
    while(cin >>n >>m >>k,n|m|k)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;

        rep(i,n)
        {
            memset(dp2,0,sizeof(dp2));

            for(int j=i; j<=m*i; ++j)
            {
                for(int k=1; k<=m; ++k)
                {
                    if(j+k>=N) break;
                    dp2[j+k]+=dp[j]/m;
                }
            }

            rep(j,N) dp[j]=dp2[j];
        }

        double ans=0;
        rep(i,N) ans+=max(1,i-k)*dp[i];

        printf("%.10lf\n",ans);
    }
    return 0;
}
