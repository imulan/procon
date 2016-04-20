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
  cin >>n;

  int h=0;
  int index=-1;
  REP(i,n){
    int g,d;
    cin >>g >>d;

    int t=g-30000*d;
    if(h<t){
      h=t;
      index=i;
    }
  }

  if(h*6>=3000000){
    printf("YES\n");
    REP(i,6) printf("%d\n", index+1);
  }
  else printf("NO\n");

  return 0;
}
