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

const int mod=1e9+7;

int dp[1000001][2]={0};
int sum[1000001][2]={0};

int main()
{
    int n,k;
    cin >>n >>k;

    //初期化
    dp[0][0]=sum[0][0]=1;
    dp[0][1]=sum[0][1]=0;

    for(int i=1; i<=n; ++i)
    {
        //この区間が0:don't stop
        //iを区間の終点として，区間はいくらでも長く出来る
        dp[i][0]=sum[i-1][1];

        //前の区間が1:stop
        //iを区間の終点として連続でk-1駅まで止まれる
        dp[i][1]=sum[i-1][0];
        if(i-k>=0)
        {
            dp[i][1]-=sum[i-k][0];
            dp[i][1]=(dp[i][1]+mod)%mod;
        }

        //sumを更新
        sum[i][0]=(sum[i-1][0]+dp[i][0])%mod;
        sum[i][1]=(sum[i-1][1]+dp[i][1])%mod;
    }

    //rep(i,n+1)rep(j,2) printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);

    cout << dp[n][1] << endl;
    return 0;
}
