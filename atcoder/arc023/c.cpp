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

int dp[2001][2001]={0};
const int mod =1e9+7;

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  vector<int> a(n);
  REP(i,n) scanf(" %d", &a[i]);

  dp[0][a[0]]=1;

  for(int i=1; i<n; ++i){
    int m=0;
    for(int j=1; j<=2000; ++j){
      dp[i][j] = m + dp[i-1][j];
      dp[i][j]%=mod;
      m=dp[i][j];
    }

    if(a[i]>=0){
      for(int j=1; j<=2000; ++j){
        if(a[i]!=j) dp[i][j]=0;
      }
    }
  }

  cout << dp[n-1][a[n-1]] << endl;
  return 0;
}
