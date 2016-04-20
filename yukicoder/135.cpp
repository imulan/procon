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
  std::vector<int> x(n);
  REP(i,n) scanf(" %d", &x[i]);

  sort(x.begin(),x.end());

  const int INF=10000000;
  int ans=INF;
  REP(i,n-1){
    int d=x[i+1]-x[i];
    if(d>0) ans=min(ans,d);
  }
  if(ans==INF) ans=0;

  std::cout << ans << std::endl;
  return 0;
}
