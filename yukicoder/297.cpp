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

  std::vector<int> num;
  int plus=1, minus=0;
  REP(i,n){
    char c;
    cin >>c;
    if('0'<=c && c<='9') num.push_back(c-'0');
    else{ //演算子
      if(c=='+') ++plus;
      else ++minus;
    }
  }

  return 0;
}
