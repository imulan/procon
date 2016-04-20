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
  long n,h,m,t;
  cin >>n >>h >>m >>t;

  long mod=24*60;

  //分換算
  long now=h*60+m;
  long add=((n-1)*t)%mod;

  now+=add;
  now%=mod;

  printf("%ld\n%ld\n", now/60, now%60);

  return 0;
}
