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
  int n, m;
  int b[500][500];

  cin >>n >>m;
  REP(i,n){
    REP(j,m){
      char c;
      scanf(" %c", &c);
      b[i][j]=c-'0';
    }
  }

  //左上から順番に見ていき、1以上のマスに遭遇したら
  //下のますにその数字を移し、その上下左右からb上のその数を引く
  int ans[500][500]={0};

  REP(i,n){
    REP(j,m){
      if(b[i][j]>0){
        int val=b[i][j];
        ans[i+1][j]+=val;
        b[i][j]-=val;
        b[i+2][j]-=val;
        b[i+1][j-1]-=val;
        b[i+1][j+1]-=val;
      }
    }
  }

  REP(i,n){
    REP(j,m){
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
