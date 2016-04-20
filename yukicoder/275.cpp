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
  std::vector<int> a(n);
  REP(i,n) scanf(" %d", &a[i]);
  sort(a.begin(),a.end());

  int t=n/2;
  if(n%2==1) printf("%d\n", a[t]);
  else printf("%lf\n", (double)(a[t]+a[t-1])/2.0);
  return 0;
}
