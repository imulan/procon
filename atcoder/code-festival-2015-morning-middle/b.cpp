#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    string s;
    cin >>n >>s;

    int ans=n;
    int S=s.size();

    for(int i=1; i<S; ++i)
    {
        string x=s.substr(0,i), y=s.substr(i);
        int X=x.size(), Y=y.size();

        //LCSを計算
        int dp[100][100]={0};
        if(x[0]==y[0]) dp[0][0]=1;

        for(int j=1; j<X; ++j)
        {
            dp[j][0]=dp[j-1][0];
            if(x[j]==y[0]) dp[j][0]=1;
        }
        for(int j=1; j<Y; ++j)
        {
            dp[0][j]=dp[0][j-1];
            if(x[0]==y[j]) dp[0][j]=1;
        }

        for(int j=1; j<X; ++j)
        {
            for(int k=1; k<Y; ++k)
            {
                if(x[j]==y[k]) dp[j][k]=dp[j-1][k-1]+1;
                else dp[j][k]=max(dp[j][k-1],dp[j-1][k]);
            }
        }

        ans = min(ans, n-2*dp[X-1][Y-1]);
    }

    cout << ans << endl;
    return 0;
}
