#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const long mod=1e9+7;
long n;

//今x歩まで進んできて、ケンがy回連続している
long dp[1000001][3];
long rec(long x, long y){
  if(dp[x][y]>=0) return dp[x][y];

  long ret=0;
  if(x==n) ret=1;
  else{
    if(y==0){//ケンしか置けない
      ret=rec(x+1,y+1);
    }
    else if(y==1){//両方おける
      long a=rec(x+1,y+1)%mod;
      long b=rec(x+1,0)%mod;
      ret=a+b;
    }
    else if(y==2){//パしか置けない
      ret=rec(x+1,0);
    }
  }

  return dp[x][y]=ret%mod;
}

int main(int argc, char const *argv[]) {
  cin >>n;
  memset(dp,-1,sizeof(dp));
  std::cout << rec(0,0) << std::endl;
  return 0;
}
