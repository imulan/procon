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

double dp[1001][1002][2]={0};

int main()
{
    int n,k;
    cin >>n >>k;

    rep(i,k+1) dp[n][i][1]=1.0;

    for(int i=n-1; i>=0; --i)
    {
        double p=1.0/(i+1);
        rep(j,k+1)
        {
            dp[i][j][1]=(1-p)*dp[i+1][j][1]+p*max(dp[i+1][j+1][1],dp[i+1][j][0]);
            dp[i][j][0]=(1-p)*dp[i+1][j][0]+p*max(dp[i+1][j+1][1],dp[i+1][j][0]);
        }
    }

    printf("%.10lf\n", dp[0][0][0]);
    return 0;
}
