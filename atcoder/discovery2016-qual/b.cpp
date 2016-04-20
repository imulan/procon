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
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  vector<int> a(n);
  REP(i,n) scanf(" %d", &a[i]);

  int ans=0;
  int l=0;
  for(int i=1; i<n; ++i){
    l=max(l,a[i]);
    if(l>a[i]) ++ans;
  }

  std::cout << ans+1 << std::endl;
  return 0;
}
