#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
const int N = 1000;
vector<int> v(N);

int dp[1002];

//現在x番目に注目
int rec(int x){
  if(x>n) return 0;
  if(dp[x]>=0) return dp[x];

  //x番目を食べる、食べない
  return dp[x] = max( rec(x+2)+v[x], rec(x+1) );
}


int main(int argc, char const *argv[]) {
  cin >>n;
  for(int i=0; i<n; ++i) scanf(" %d", &v[i]);
  fill(dp,dp+n+1,-1);
  printf("%d\n", rec(0));
  return 0;
}
