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
  string s[3]={"Won", "Drew", "Lost"};
  string rps[3][3] ={
    {s[1],s[0],s[2]},
    {s[2],s[1],s[0]},
    {s[0],s[2],s[1]}
  };

  int n,k;
  cin >>n >>k;
  std::cout << rps[n][k] << std::endl;
  return 0;
}
