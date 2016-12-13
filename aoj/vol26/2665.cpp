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
int dp[5001][5001]={};

int main()
{
    int n,L;
    scanf(" %d %d", &n, &L);
    vector<int> x(n), a(n);
    rep(i,n) scanf(" %d", &x[i]);
    rep(i,n) scanf(" %d", &a[i]);

    if(a[0]==0) dp[0][x[0]]=1;
    else for(int i=x[0]; i<L; i+=a[0]) dp[0][i]=1;

    for(int i=1; i<n; ++i)
    {
        int sum=0;
        if(a[i]==0)
        {
            rep(j,x[i]) (sum+=dp[i-1][j])%=mod;
            dp[i][x[i]]=sum;
        }
        else
        {
            rep(j,L)
            {
                if(j-x[i]>=0 && (j-x[i])%a[i]==0) dp[i][j]=sum;
                (sum+=dp[i-1][j])%=mod;
            }
        }
    }

    int ans=0;
    rep(i,L) (ans+=dp[n-1][i])%=mod;
    printf("%d\n", ans);
    return 0;
}
