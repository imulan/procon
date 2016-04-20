#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  int n;
  int a[100][100];
  scanf(" %d",&n);
  rep(i,n)rep(j,i+1) scanf(" %d", &a[i][j]);

  int dp[100][100]={0};
  dp[0][0]=a[0][0];
  for(i=1; i<n; ++i){
    dp[i][0]=dp[i-1][0]+a[i][0];
    dp[i][i]=dp[i-1][i-1]+a[i][i];
    for(j=1; j<i; ++j)
      dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
  }

  int ans=0;
  rep(i,n) ans=max(ans,dp[n-1][i]);
  std::cout << ans << std::endl;
  return 0;
}
