#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int A,B;
int a[1001]={0}, b[1001]={0};

int dp[1002][1002];

int rec(int x, int y){
  int ret=0;
  if(dp[x][y]>=0) return dp[x][y];

  //両方の山が空
  if(x==A && y==B) ret = 0;
  else if((x+y)%2==0){ //先手
    if(x==A) ret = rec(x,y+1)+b[y];
    else if(y==B) ret = rec(x+1,y)+a[x];
    else ret = max( rec(x+1,y)+a[x], rec(x,y+1)+b[y] );
  }
  else{ //後手
    if(x==A) ret = rec(x,y+1);
    else if(y==B) ret = rec(x+1,y);
    else ret = min( rec(x+1,y), rec(x,y+1) );
  }

  return dp[x][y] = ret;
}

int main(int argc, char const *argv[]) {
  cin >>A >>B;
  for(int i=0; i<A; ++i) scanf("%d", &a[i]);
  for(int i=0; i<B; ++i) scanf("%d", &b[i]);
  memset(dp,-1,sizeof(dp));
  printf("%d\n", rec(0,0));
  return 0;
}
