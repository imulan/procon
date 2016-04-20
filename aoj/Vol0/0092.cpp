#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

char f[1000][1000];
int dp[1000][1000];

int main(int argc, char const *argv[]) {
  int i,j;
  while(1){
    int n;
    cin >>n;
    if(n==0) break;

    rep(i,n)rep(j,n) scanf(" %c", &f[i][j]);
    memset(dp,0,sizeof(dp));

    rep(i,n){
      if(f[0][i]!='*') dp[0][i]=1;
      if(f[i][0]!='*') dp[i][0]=1;
    }

    for(i=1; i<n; ++i){
      for(j=1; j<n; ++j){
        if(f[i][j]=='*') dp[i][j]=0;
        else dp[i][j]=min( dp[i][j-1], min(dp[i-1][j-1],dp[i-1][j]) )+1;
      }
    }

    /*
    rep(i,n){
      rep(j,n) printf("%2d ",dp[i][j]);
      printf("\n");
    }
    */
    
    int ans=0;
    rep(i,n)rep(j,n) ans=max(ans,dp[i][j]);

    std::cout << ans << std::endl;
  }
  return 0;
}
