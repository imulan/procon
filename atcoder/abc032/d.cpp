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

int n,W;
int v[200];
int w[200];


//(n<=30)x番目に注目、残り容量y
long rec(int x, int y){
  long ret=0;

  if(x==n) ret=0;
  else if(y<w[x]) ret=rec(x+1,y);
  else ret=max(rec(x+1,y),rec(x+1,y-w[x])+v[x]);

  return ret;
}

/*
//(w_i<=1000) 今の重さy
long rec2(int x, int y){
  if(dp[x][y]>=0) return dp[x][y];

  long ret=0;
  if(x==n) ret=0;
  else if(y<w[x]) ret=rec(x+1,y);
  else ret=max(rec(x+1,y),rec(x+1,y-w[x])+v[x]);

  return dp[x][y]=ret;
}
*/

long dp[201][210000];

int main(int argc, char const *argv[]) {
  cin >>n >>W;
  bool ww=true, vv=true;
  REP(i,n){
    scanf(" %d %d", &v[i], &w[i]);
    if(v[i]>1000) vv=false;
    if(w[i]>1000) ww=false;
  }

  long ans;

  if(ww){
    if(W>200000) W=200000;
    memset(dp,0,sizeof(dp));

    for(int i=n-1; i>=0; --i){
      REP(j,W+1){
        if(j<w[i]) dp[i][j]=dp[i+1][j];
        else{
          dp[i][j]=max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
        }
      }
    }

    ans=dp[0][W];
  }
  else if(vv){ //価値
    const long INF=100000000000;
    //初期化
    REP(i,201)REP(j,210000) dp[i][j]=INF;
    dp[0][0]=0;

    REP(i,n){
      REP(j,210000){
        if(j<v[i]) dp[i+1][j]=dp[i][j];
        else dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
      }
    }

    REP(i,210000){
      if(dp[n][i]<=W) ans=i;
    }
  }
  else if(n<=30) ans=rec(0,W);

  printf("%ld\n", ans);

  return 0;
}
