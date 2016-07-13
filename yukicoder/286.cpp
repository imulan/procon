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

int n;
int m[15];

int dp[1<<15];
int dfs(int mask)
{
    if(dp[mask]>=0) return dp[mask];

    //全ての商品購入が終わった
    if(mask==(1<<n)-1) return 0;

    //値引き額
    int discount=0;
    rep(i,n)
    {
        if(mask>>i&1) (discount+=m[i])%=1000;
    }

    int ret=12345678;
    //次に買う商品i
    rep(i,n)
    {
        if(mask>>i&1) continue;
        int add=max(0,m[i]-discount);
        ret=min(ret,dfs(mask+(1<<i))+add);
    }

    return dp[mask]=ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>m[i];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0) << endl;
    return 0;
}
