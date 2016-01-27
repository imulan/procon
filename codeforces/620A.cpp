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

long ab(long p){
  return (p>0)?p:-p;
}

int main(int argc, char const *argv[]) {
  long x1,y1,x2,y2;

  cin >>x1 >>y1 >>x2 >>y2;

  long dx=ab(x1-x2), dy=ab(y1-y2);

  std::cout << max(dx,dy) << std::endl;
  return 0;
}
