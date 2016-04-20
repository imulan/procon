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
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  std::vector<int> x(n),y(n);
  REP(i,n) cin >>x[i] >>y[i];

  int ans=0;
  REP(i,n){
    REP(j,n){
      int dx=x[i]-x[j], dy=y[i]-y[j];
      ans=max(ans,dx*dx+dy*dy);
    }
  }

  printf("%.10lf\n",(double)sqrt(ans));
  return 0;
}
