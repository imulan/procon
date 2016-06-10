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

//aのi文字目を終端，bのj文字目を終端にした時の共通部分列の長さ
int dp[4000][4000];

int main()
{
    string a,b;
    while(cin >>a >>b)
    {
        //initialize
        memset(dp,0,sizeof(dp));

        int A=a.size(), B=b.size();

        rep(i,A) if(a[i]==b[0]) dp[i][0]=1;
        rep(i,B) if(a[0]==b[i]) dp[0][i]=1;

        for(int i=1; i<A; ++i)for(int j=1; j<B; ++j)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        }

        int ans=0;
        rep(i,A)rep(j,B) ans=max(ans,dp[i][j]);

        cout << ans << endl;
    }
    return 0;
}
