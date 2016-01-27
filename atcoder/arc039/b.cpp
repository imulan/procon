#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int mod=1e9+7;

int main(int argc, char const *argv[]) {
  int n,k;
  cin >>n >>k;

  //組合せ
  int c[601][601]={0};
  for(int i=0; i<=600; ++i) c[i][0]=c[i][i]=1;

  for(int i=2; i<=600; ++i){
    for(int j=1; j<i; ++j){
      c[i][j]=c[i-1][j]+c[i-1][j-1];
      c[i][j]%=mod;
    }
  }

  int ans;
  if(n>k){ //必ずもらえない人が出るのでどのように組んでもよい
    ans = c[n-1+k][n-1];
  }
  else{
    ans = c[n][k%n];
  }

  printf("%d\n", ans);
  return 0;
}
