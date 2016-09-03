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
  int n;
  long k;
  cin >>n >>k;
  vector<long> s(n);

  bool zero=false;

  REP(i,n){
    scanf(" %d", &s[i]);
    if(s[i]==0) zero=true;
  }

  int ans=0;

  if(zero) ans=n;
  else{
    long now=1;
    int st=0; //区間開始位置のindex
    //しゃくとり法
    REP(i,n){
      if(now*s[i]>k){ //次のをかけると超えてしまう
        if(now<=k) ans=max(ans, i-st); //更新
        //printf("st %d, ans:%d\n", st,ans);
        while(i!=st && now*s[i]>k){
          now/=s[st];
          ++st;
        }
      }

      now*=(long)s[i];
      //printf("%d: %ld\n",i,now);
    }
    if(now<=k) ans=max(ans,n-st);
  }

  printf("%d\n", ans);

  return 0;
}
