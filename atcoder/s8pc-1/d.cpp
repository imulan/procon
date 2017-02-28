#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod=1e9+7;

int dp[1000][1000];

int main()
{
    int H,W,K;
    scanf(" %d %d %d", &H, &W, &K);

    fill(dp[0],dp[1000],1);

    while(K--)
    {
        int X,Y;
        scanf(" %d %d", &X, &Y);

        if(X!=1) for(int i=Y+1; i<H; ++i) dp[i][X-2]=0;
        if(Y!=1) for(int i=X+1; i<W; ++i) dp[Y-2][i]=0;
    }

    for(int i=1; i<H; ++i)for(int j=1; j<W; ++j)
    {
        if(dp[i][j]) dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
    }

    printf("%d\n", dp[H-1][W-1]);
    return 0;
}
