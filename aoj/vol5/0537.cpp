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

int dp[50][3001];
int newdp[50][3001];

int main()
{
    const int mod=100000;
    int n,m,s;
    while(cin >>n >>m >>s,n)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;

        //iを使うかどうか
        for(int i=1; i<=m; ++i)
        {
            memset(newdp,0,sizeof(newdp));

            rep(j,n*n+1)rep(k,s+1)
            {
                //使う
                if(j<n*n && k+i<=s)
                {
                    newdp[j+1][k+i]+=dp[j][k];
                    newdp[j+1][k+i]%=mod;
                }

                //使わない
                newdp[j][k]+=dp[j][k];
                newdp[j][k]%=mod;
            }

            //copy
            rep(j,n*n+1)rep(k,s+1) dp[j][k]=newdp[j][k];
        }

        cout << dp[n*n][s] << endl;
    }
    return 0;
}
