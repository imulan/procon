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
  if(s[k-1]=='('){
    //indexを増やす方向に対応を探しに行く
    int now=0;
    REP(i,k-1){
      if(s[i]=='(') ++now;
      else --now;
    }

    int st=now;
    for(int i=k-1; i<s.size(); ++i){
      if(s[i]=='(') ++now;
      else --now;

      if(now==st){
        ans=i+1;
        break;
      }
    }
  }
  else{
    //indexを減らす方向に対応を探しに行く
    int now=0;
    for(int i=s.size()-1; i>k-1; --i){
      if(s[i]=='(') ++now;
      else --now;
    }

    int st=now;
    for(int i=k-1; i>=0; --i){
      if(s[i]=='(') ++now;
      else --now;

      if(now==st){
        ans=i+1;
        break;
      }
    }
  }


  std::cout << ans << std::endl;
  return 0;
}
