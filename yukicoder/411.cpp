#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,k;
ll dp[1<<20][20][2];

ll dfs(int mask, int prev, int big)
{
    if(dp[mask][prev][big]>=0) return dp[mask][prev][big];
    if(mask == (1<<n)-1) return big;


    ll ret=0;

    rep(i,n)
    {
        if(mask>>i&1) continue;

        if(i>prev) ret+=dfs(mask+(1<<i), i, big);
        else
        {
            if(big==0) ret+=dfs(mask+(1<<i), i, 1);
        }
    }

    return dp[mask][prev][big]=ret;
}

int main()
{
    cin >>n >>k;
    --k;
    memset(dp,-1,sizeof(dp));
    cout << dfs(1<<k,k,0) << endl;
    return 0;
}
