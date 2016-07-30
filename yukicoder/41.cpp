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

const int mod=1e9+9;
int dp[90002]={0};
int sumdp[90002]={0};

int main()
{
    dp[0]=sumdp[0]=1;
    for(int i=1; i<=9; ++i)
    {
        int sum[10]={0};
        rep(j,90002)
        {
            (sum[j%i]+=dp[j])%=mod;
            dp[j]=sum[j%i];
            // if(i>1) printf("i=%d, dp[%d] = %d\n", i,j,dp[j]);
        }
    }

    for(int i=1; i<=90001; ++i) sumdp[i]=(sumdp[i-1]+dp[i])%mod;

    int T;
    cin >>T;
    rep(times,T)
    {
        ll m;
        cin >>m;
        cout << sumdp[m/111111] << endl;
    }
    return 0;
}
