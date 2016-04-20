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
  int n,k;
  string s;
  cin >>n >>k >>s;

  int ans=-1;
  if(k<=n){ //1箱目の途中で終わるのは普通にシミュレーション
    int b=0; //buy
    int st=0; //stock
    REP(i,k){
      if(st>0) --st;
      else ++b;
      st+=s[i]-'0';
    }
    ans=b;
  }
  else{
    //とりあえず1周回すとどうなるか見る
    int b=0; //buy
    int st=0; //stock
    REP(i,n){
      if(st>0) --st;
      else ++b;
      st+=s[i%n]-'0';
    }
    //printf("b:%d, st:%d\n",b,st);

    if(b>st) b+=(k/n-1)*(b-st);
    else if(b<st) st+=(k/n-1)*(st-b);
    //printf("b:%d, st:%d\n",b,st);

    //最後1回
    REP(i,k%n){
      if(st>0) --st;
      else ++b;
      st+=s[i%n]-'0';
    }
    //printf("b:%d, st:%d\n",b,st);
    ans=b;
  }


  std::cout << ans << std::endl;
  return 0;
}
