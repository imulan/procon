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

const int N=1<<16;

int main()
{
    int n;
    cin >>n;
    vector<int> d(n);
    rep(i,n) cin >>d[i];

    int dp[N]={0};
    dp[0]=100;

    rep(mask,1<<n)
    {
        if(dp[mask]<=0) continue;

        //最大体力
        int lim=100;
        rep(i,n)
        {
            if(mask>>i&1 && d[i]<0) lim+=100;
        }

        //printf("mask = %d, lim = %d\n", mask,lim);

        //次に戦う敵
        rep(i,n)
        {
            if(mask>>i&1) continue;

            if(d[i]>0)
            {
                int nx=min(lim,dp[mask]+d[i]);
                int nst=mask+(1<<i);
                dp[nst]=max(dp[nst],nx);
                //printf(" nst = %d\n", nst);
            }
            else
            {
                if(dp[mask]+d[i]>0)
                {
                    int nst=mask+(1<<i);
                    dp[nst]=max(dp[nst],dp[mask]+d[i]);
                    //printf(" nst = %d\n", nst);
                }
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;
    return 0;
}
