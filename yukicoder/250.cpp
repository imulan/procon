#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll dp[1501][1501]={0};
ll INF=(ll)1e15+1;

int main(int argc, char const *argv[]) {
  //予めdpを計算させておく
  int i,j;
  dp[0][0]=1;
  for(i=1; i<=1500; ++i){

    ll sum=0;
    rep(j,1501){
      if(sum==INF) dp[i][j]=INF;
      else{
        if(dp[i-1][j]>=INF-sum){
          sum=INF;
          dp[i][j]=INF;
        }
        else{
          dp[i][j]=sum+dp[i-1][j];
          sum=dp[i][j];
        }
      }
    }

  }

  int q;
  int Q;
  cin >>Q;

  rep(q,Q){
    int d,x;
    ll t;
    cin >>d >>x >>t;
    //cout <<dp[d][x]<< endl;

    string ans="ZETUBOU";
    if(dp[d][x]!=INF && dp[d][x]<=t) ans="AC";
    std::cout << ans << std::endl;
  }
  return 0;
}
