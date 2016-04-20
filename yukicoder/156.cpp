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
  int n,m;
  cin >>n >>m;
  std::vector<int> c(n);
  REP(i,n) cin >>c[i];

  sort(c.begin(),c.end());

  int ans=0;
  REP(i,n){
    if(m>=c[i]){
      m-=c[i];
      ++ans;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
