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

const int N=300;
int dp[601][601]={};
int nx[601][601];

int main()
{
    int n,K;
    string s;
    cin >>n >>K >>s;

    dp[0+N][0+N] = 1;
    rep(i,n)
    {
        memset(nx,0,sizeof(nx));
        bool zero=true, one=true;
        if(s[i]=='0') one=false;
        if(s[i]=='1') zero=false;

        for(int j=-K; j<=K; ++j)for(int k=j; k<=K; ++k)
        {
            if(zero)
            {
                if(j > -K)
                {
                    int nj = min(j-1,-1);
                    int nk = max(k-1,-1);

                    (nx[nj+N][nk+N]+=dp[j+N][k+N])%=mod;
                }
            }
            if(one)
            {
                if(k < K)
                {
                    int nj = min(j+1,1);
                    int nk = max(k+1,1);

                    (nx[nj+N][nk+N]+=dp[j+N][k+N])%=mod;
                }
            }
        }

        rep(j,601)rep(k,601) dp[j][k]=nx[j][k];
    }

    int ans=0;
    for(int i=-K; i<=K; ++i)for(int j=i; j<=K; ++j) (ans+=dp[i+N][j+N])%=mod;
    cout << ans << endl;
    return 0;
}
