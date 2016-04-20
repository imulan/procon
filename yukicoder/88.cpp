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
  string s,t,b[8];

  cin >>s;
  if(s=="oda") t="yukiko";
  else t="oda";

  REP(i,8) cin >>b[i];

  int ct=0;
  REP(i,8){
    REP(j,8){
      if(b[i][j]!='.') ++ct;
    }
  }

  string ans;
  if(ct%2==0) ans=s;
  else ans=t;

  std::cout << ans << std::endl;
  return 0;
}
