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

int ab(int p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  int x,y,r;
  cin >>x >>y >>r;

  //上下左右対称なので第１象限で考える
  x=ab(x);
  y=ab(y);

  double sq=(double)2.0*r/sqrt(2);
  sq+=x+y;

  std::cout << (int)sq+1 << std::endl;

  return 0;
}
