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

bool ch(int a, int b, int c){
  if(a==b || b==c || a==c) return false;

  if(a>b && c>b) return true;
  if(b>a && b>c) return true;

  return false;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  std::vector<int> a(n);
  REP(i,n) cin >>a[i];

  int ans=0;
  for(int i=1; i<n-1; ++i){
    if(ch(a[i-1],a[i],a[i+1])) ++ans;
  }

  std::cout << ans << std::endl;
  return 0;
}
