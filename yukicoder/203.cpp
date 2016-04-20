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
  char c[16];
  REP(i,14) scanf(" %c", &c[i]);
  c[14]='x';

  int ans=0;
  REP(i,14){
    if(c[i]=='o'){
      int st=i;
      while(c[i]=='o')++i;
      ans=max(ans,i-st);
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
