#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  vector<int> p(n);
  for(int i=0; i<n; ++i) scanf(" %d", &p[i]);

  bool dp[10001];
  //初期化
  for(int i=0; i<=10000; ++i) dp[i]=false;
  dp[0]=true;

  for(int a=0; a<n; ++a){
    for(int i=a*100; i>=0; --i){
      if(dp[i]) dp[i+p[a]]=true;
    }
  }

  int ans=0;
  for(int i=0; i<=10000; ++i) {
    ans += dp[i];
    //if(dp[i]) printf(" %d\n", i);
  }
  printf("%d\n", ans);

  return 0;
}
