#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main(int argc, char const *argv[]) {
  int n, m;
  scanf(" %d %d", &n, &m);

  vector<int> f(n+1);
  for(int i=1; i<=n; ++i) scanf(" %d", &f[i]);

  int dp[100001]={0}; //サプリiまでを食べる組合せ
  int ate[100001]={0}; //サプリiをその日に食べたか

  int st=0; //区間の始点
  dp[0]=1;
  int _d=1;

  for(int i=1; i<=n; ++i){
    //その日食べようとしているサプリをもう食べてる
    if(ate[f[i]]>0){
      while (ate[f[i]]>0){
        --ate[f[st]];
        _d = (_d-dp[st]+MOD)%MOD;
        ++st;
      }

      --st;
      ++ate[f[st]];
      _d+=dp[st];
      _d%=MOD;
    }
    ++ate[f[i]];
    dp[i]=_d;
    _d+=dp[i];
    _d%=MOD;

    //printf("st=%d, dp[%d]= %d\n", st, i, dp[i]);
  }

  printf("%d\n", dp[n]);

  return 0;
}
