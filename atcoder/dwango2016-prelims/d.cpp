#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int h,w;
long b[301][301]={0};
const long INF = (1<<30);
//左上を(i,j)、右下を(h,w)とした長方形を考えた時に作れるきれいさの最大値
long dp[301][301];

int main(int argc, char const *argv[]) {
  //i行目を1~j列の累積和
  long yoko[301][301]={0};

  cin >>h >>w;

  for(int i=1; i<=h; ++i){
    for(int j=1; j<=w; ++j){
      scanf(" %ld", &b[i][j]);
      yoko[i][j]=b[i][j]+yoko[i][j-1];
    }
  }
  /*
  for(int i=1; i<=h; ++i){
    for(int j=1; j<=w; ++j){
      printf("%3d", yoko[i][j]);
    }
    printf("\n");
  }
  */

  long ans=-INF;


  std::cout << ans << std::endl;
  return 0;
}
