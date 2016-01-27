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

int main(int argc, char const *argv[]) {
  unsigned long long  z=0;
  cout << z-1 << endl;

  int h,w;
  char f[510][510]; //[1~h][1~w]

  cin >>h >>w;
  REP(i,h){
    REP(j,w){
      scanf(" %c", &f[i+1][j+1]);
    }
  }

  FOR(i,0,h+1){
    f[i][0]='X';
    f[i][w+1]='X';
  }
  FOR(i,0,w+2){
    f[0][i]='X';
    f[h+1][i]='X';
  }

  //(1,1)と(i,j)で囲まれた長方形の中で作れる個数
  long t1[510][510]={0};
  //まず縦の関係を埋めていく
  for(long i=1; i<=w; ++i){
    for(long j=1; j<=h; ++j) t1[j][i] = t1[j][i-1];

    long tate[510]={0};

    for(long j=2; j<=h; ++j){
      long tt=0;
      if(f[j-1][i]=='.' && f[j][i]=='.') tt=1;
      tate[j] += tate[j-1]+tt;
    }

    for(long j=1; j<=h; ++j) t1[j][i] += tate[j];
  }

  //次に横の関係
  long t2[510][510]={0};

  for(long i=1; i<=h; ++i){
    for(long j=1; j<=w; ++j) t2[i][j] = t2[i-1][j];

    long yoko[510]={0};

    for(long j=2; j<=w; ++j){
      long tt=0;
      if(f[i][j-1]=='.' && f[i][j]=='.') tt=1;
      yoko[j] = yoko[j-1]+tt;
    }

    for(long j=1; j<=w; ++j) t2[i][j] += yoko[j];
  }

  long t[510][510]={0}; //2つを合わせる
  for(long i=0; i<=h; ++i){
    for(long j=0; j<=w; ++j){
      t[i][j] = t1[i][j]+t2[i][j];
    }
  }

  //check
  /*
  for(long i=1; i<=h; ++i){
    for(long j=1; j<=w; ++j){
      printf("%4ld", t1[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(long i=1; i<=h; ++i){
    for(long j=1; j<=w; ++j){
      printf("%4ld", t2[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for(long i=0; i<=h; ++i){
    for(long j=0; j<=w; ++j){
      printf("%4ld", t[i][j]);
    }
    printf("\n");
  }
  */

  //query
  long q;
  cin >>q;
  for(long Q=0; Q<q; ++Q){
    long r1,c1,r2,c2;
    cin >>r1 >>c1 >>r2 >>c2;
    long ans=t[r2][c2]-t[r2][c1-1]-t[r1-1][c2]+t[r1-1][c1-1];

    //縁を除外、上と左を調べる
    for(long i=r1; i<=r2; ++i){
      if(f[i][c1]=='.' && f[i][c1-1]=='.') --ans;
    }

    for(long i=c1; i<=c2; ++i){
      if(f[r1][i]=='.' && f[r1-1][i]=='.') --ans;
    }

    cout << ans << endl;
  }

  return 0;
}
