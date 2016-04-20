#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  int sum=0;

  cin >>n;
  vector<int> w(n);

  for(int i=0; i<n; ++i){
    scanf(" %d", &w[i]);
    sum += w[i];
  }


  if(sum%2==0){
    //x番目までで重さyをつくれるか
    bool dp[101][5101];

    for(int i=0; i<n; ++i)
    for(int j=0; j<=sum/2; ++j)
    dp[i][j]=false;

    //初期化
    for(int i=0; i<n; ++i) dp[i][0]=true;
    dp[0][w[0]] =true;
    for(int i=1; i<n; ++i){
      for(int j=0; j<=sum/2; ++j) dp[i][j]=dp[i-1][j];

      for(int j=0; j<=sum/2; ++j){
        if(dp[i-1][j] && j+w[i]<=sum/2) dp[i][j+w[i]] = true;
      }
    }

    /*
    for(int i=0; i<n; ++i){
      for(int j=0; j<=sum/2; ++j) printf(" %d", dp[i][j]);
      printf("\n");
    }
    */
    if(dp[n-1][sum/2]) printf("possible\n");
    else printf("impossible\n");
  }
  else printf("impossible\n");
  return 0;
}
