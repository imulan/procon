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

const int INF=1234567890;

//i日目までにj回勝率が上昇した時の勝利数の最小値
int dp[2001][2001];

int main()
{
    int n,k;
    cin >>n >>k;

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> suma(n+1);
    suma[0]=0;
    for(int i=1; i<=n; ++i) suma[i]=suma[i-1]+a[i-1];

    if(suma[n]==k)
    {
        printf("1\n");
        return 0;
    }

    fill(dp[0],dp[2001],INF);
    dp[0][0]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    for(int i=2; i<=n; ++i)
    {
        dp[i][0]=0;

        for(int j=1; j<=i; ++j)
        {
            ll x=(ll)dp[i-1][j-1]*suma[i]/suma[i-1] + 1;
            // printf("   %d * %d / %d\n",dp[i-1][j-1],suma[i],suma[i-1]);
            // printf("(%d,%d) : x= %lld\n",i,j,x);

            if(x-dp[i-1][j-1]<=a[i-1]) dp[i][j]=min(dp[i][j],(int)x);
            dp[i][j]=min(dp[i][j],dp[i-1][j]);

            // printf(" dp[%d][%d]= %d\n",i,j,dp[i][j]);
        }
    }

    int ans=-1;
    for(int i=n; i>=0; --i)
    {
        // printf("dp[n][%d] = %d\n", i,dp[n][i]);
        if(dp[n][i]<=k)
        {
            ans=i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
