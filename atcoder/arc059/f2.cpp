#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll mod=1e9+7;

ll mod_pow(int x, int n)
{
    ll pw[31];
    pw[0]=x;
    for(int i=1; i<31; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,31)
    {
        if(n&(1<<i)) (ret*=pw[i])%=mod;
    }
    return ret;
}

ll mod_inv(int x)
{
    return mod_pow(x,mod-2);
}

ll dp[5001][5001]={0};

int main()
{
    int n;
    string s;
    cin >>n >>s;

    int S=s.size();

    dp[0][0]=1;
    rep(i,n)rep(j,i+1)
    {
        (dp[i+1][j+1]+=(dp[i][j]*2)%mod)%=mod;
        (dp[i+1][max(0,j-1)]+=dp[i][j])%=mod;
    }

    ll ans=dp[n][S];
    ans*=mod_inv(mod_pow(2,S));
    cout << ans%mod << endl;
    return 0;
}
