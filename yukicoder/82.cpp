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
  int w,h;
  char c[2];
  cin >>w >>h >>c[0];

  char d;
  if(c[0]=='B') c[1]='W';
  else c[1]='B';

  REP(i,h){
    REP(j,w){
      printf("%c", c[(i+j)%2]);
    }
    printf("\n");
  }

  return 0;
}
