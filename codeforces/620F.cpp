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
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

//func(1,i)を保存

long f[1000001]={0};

long p,q;
long a[50000];
long L[5000],R[5000],ans[5000];

long dp[2][50000]={0}; //0:old,1:new

vector<long> wid[50000];

int main(int argc, char const *argv[]) {
  //input
  scanf(" %ld %ld",&p,&q);
  for(long i=0; i<p; ++i) scanf(" %ld", &a[i]);


  for(long i=0; i<q; ++i){
    scanf(" %ld %ld", &L[i], &R[i]);
    --L[i];
    --R[i];
    if(L[i]==R[i]) ans[i]=a[L[i]];
    else{
      wid[R[i]-L[i]].push_back(i);
      ans[i]=0;
    }
  }

  //solve
  f[1]=1;
  for(long i=2; i<=1000000; ++i) f[i]=f[i-1]^i;

  //dp
  for(long i=0; i<p; ++i) dp[0][i]=a[i];

  for(long i=1; i<p; ++i){
    for(long j=0; j<p-i; ++j){
      dp[1][j]=max(f[max(a[j],a[j+i])]^f[min(a[j],a[j+i])-1], max(dp[0][j],dp[0][j+1]));
      dp[0][j]=dp[1][j];
    }

    for(long j=0; j<wid[i].size(); ++j){
      ans[wid[i][j]] = dp[1][L[wid[i][j]]];
    }
  }

  //output
  for(long i=0; i<q; ++i) printf("%ld\n", ans[i]);
  return 0;
}
