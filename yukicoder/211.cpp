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
  int k;
  cin >>k;

  int p[6]={2,3,5,7,11,13};
  int q[6]={4,6,8,9,10,12};

  double ans=0;
  REP(i,6){
    REP(j,6){
      if(p[i]*q[j]==k) ans+=1.0;
    }
  }

  printf("%.20lf\n", ans/36);
  return 0;
}
