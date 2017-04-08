#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

ll dp[2010101]={};

ll solve(ll n)
{
    dp[0]=1;
    ll sum=1;
    for(int i=1; i<=n; ++i)
    {
        dp[i] = sum;
        // printf("%s\n", );
        if(i-2>=0) dp[i] = (dp[i]-dp[i-2]+mod)%mod;
        (sum+=dp[i])%=mod;
    }

    sum = (sum-dp[n]-dp[n-1]+mod*2)%mod;
    dp[n+1] = sum;

    for(int i=n+2; i<2*n; ++i)
    {
        sum = (sum-dp[i-(n+1)-1]+mod)%mod;
        dp[i] = sum;
    }

    ll ret=0;
    ll sq = ((n-1)*(n-1))%mod;
    rep(i,n-1)
    {
        (ret+=(dp[i]*sq)%mod)%=mod;
    }
    (ret+=(dp[n-1]*(n-1))%mod)%=mod;
    for(int i=n; i<=2*n; ++i) (ret+=dp[i])%=mod;
    return ret;
}

int main()
{
    ll n;
    cin >>n;
    cout << solve(n) << endl;
    return 0;
}
