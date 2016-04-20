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
  int a,b,x,y;
  cin >>a >>b >>x >>y;

  double p=(double)x/a;
  double q=(double)y/b;

  double ans=0;
  if(p<q){
    ans+=x;
    ans+=(double)x*b/a;
  }
  else{
    ans+=y;
    ans+=(double)y*a/b;
  }

  printf("%.20lf\n", ans);
  return 0;
}
