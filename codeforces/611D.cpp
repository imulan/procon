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

const long mod=(long)1e9+7;

int n;
string str;

int s[5001];

long dp[5005][5005]={0};
long dpsum[5005][5005]={0}; //sum of dp[1..a][b]

int nxt[5005][5005]={0};


int main(int argc, char const *argv[]) {
  cin >>n >>str;

  for(int i=1; i<=n; ++i) s[i]=str[i-1]-'0';

  //まずnxtを埋めておく
  for(int a=n-1; a>=1; --a){
    for(int b=n-1; b>0; --b){
      nxt[a][b]=((s[a]!=s[b]) ? 0 : (nxt[a+1][b+1]+1) );
      //printf("nxt[%d][%d]= %d\n",a,b,nxt[a][b]);
    }
  }

  for(int c=1; c<=n; ++c){
    dp[1][c]=1;

    for(int b=1; b<=c; ++b){
      if(s[b]!=0){
        int a=2*b-c;
        if(a<1) a=1;

        dp[b][c] += dpsum[b-1][b-1]-dpsum[a-1][b-1];
        if(dp[b][c]<0) dp[b][c]+=mod;

        a=2*b-c-1;
        if(a>=1){
          int d=nxt[a][b];
          if(d<=c-b && s[a+d]<s[b+d])
            dp[b][c]=(dp[b][c]+dp[a][b-1])%mod;
        }

        //printf("dp[%d][%d] = %d\n", b,c,dp[b][c]);
      }

      dpsum[b][c]=(dpsum[b-1][c]+dp[b][c])%mod;
    }
    
  }

  std::cout << dpsum[n][n] << std::endl;

  return 0;
}
