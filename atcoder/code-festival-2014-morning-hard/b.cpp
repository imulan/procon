#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod = 1e9+7;

int n;
int p[1000],l[1000];

int dp[1000][2001]={};
int sum[2001];

int main()
{
    scanf(" %d", &n);
    rep(i,n) scanf(" %d %d", &p[i], &l[i]);

    rep(i,2*l[0]+1) dp[0][i]=1;
    for(int i=1; i<n; ++i)
    {
        memset(sum,0,sizeof(sum));
        sum[0]=dp[i-1][0];
        for(int j=1; j<=2000; ++j) sum[j] = (sum[j-1]+dp[i-1][j])%mod;

        rep(j,2*l[i]+1)
        {
            int pos = p[i]-l[i]+j;

            if(pos <= p[i-1]-l[i-1]) continue;

            int idx = 2*l[i-1];
            if(pos <= p[i-1]+l[i-1]) idx = pos-(p[i-1]-l[i-1])-1;
            dp[i][j] = sum[idx];
        }
    }

    int ans = 0;
    rep(i,2*l[n-1]+1) (ans+=dp[n-1][i])%=mod;
    printf("%d\n", ans);
    return 0;
}
