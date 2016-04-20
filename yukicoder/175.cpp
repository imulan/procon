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
  int L, n;
  cin >>L >>n;
  vector<string> s(n);
  REP(i,n) cin >>s[i];

  int pw[30]={0};
  pw[0]=1;
  REP(i,29) pw[i+1]=pw[i]*2;

  std::cout << pw[L-3]*n << std::endl;
  return 0;
}
