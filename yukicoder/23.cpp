#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int h,a,d;
double dp[10001];

//damage分のダメージを与えるために必要な攻撃回数の期待値の最小
double rec(int damage){
  if(damage >= h) return 0;
  if(dp[damage]>=0) return dp[damage];
  return dp[damage] = min( rec(damage+a)+1, rec(damage+d)+1.5  );
}

int main(int argc, char const *argv[]) {
  cin >>h >>a >>d;
  fill(dp,dp+h,-1);
  printf("%lf\n", rec(0));
  return 0;
}
