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

  //必要数6,2,5,5,4,5,6,3,6
  //桁数が多いほうが大きいから1を作りまくる

  string ans="";

  if(n%2==1){
    ans = "7";
    n-=3;
  }
  REP(i,n/2){
    ans = ans+"1";
  }

  std::cout << ans << std::endl;
  return 0;
}
