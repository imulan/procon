#include <cstdio>
#include <iostream>
using namespace std;

const long mod = 1000000007;

int main(){
  int k, ball[1000]={0};
  long c[1001][1001]={0};

  //input
  scanf(" %d", &k);
  for(int i=0; i<k; ++i) scanf(" %d", &ball[i]);

  //組み合わせの値をパスカルの三角形的に計算しておく
  for(int i=0; i<=1000; ++i){
    c[i][0]=1;
    c[i][i]=1;
  }

  for(int i=2; i<=1000; ++i){
    for(int j=1; j<i; ++j) c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
  }

  long long ans=1;
  //solve
  for(int i=1; i<k; ++i){
    long first=-1;
    for(int j=0; j<=i; ++j) first+=ball[j];

    ans = (ans*c[first][ball[i]-1])%mod;
  }

  cout << ans << endl;
}
