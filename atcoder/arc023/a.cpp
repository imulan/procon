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

int days(int y, int m, int d){
  if(m<=2){
    --y;
    m+=12;
  }

  return (365*y + y/4 - y/100 + y/400 + (306*(m+1))/10 + d - 429);
}

int main(int argc, char const *argv[]) {
  int y,m,d;
  cin >>y >>m >>d;

  std::cout << days(2014,5,17)-days(y,m,d) << std::endl;

  return 0;
}
