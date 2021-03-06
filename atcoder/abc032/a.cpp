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

int gcd(int x,int y){
  if(x<y) swap(x,y);

  if(x%y==0) return y;
  else return gcd(y,x%y);
}

int main(int argc, char const *argv[]) {
  int a,b,n;
  cin >>a >>b >>n;

  int lcm = a*b/gcd(a,b);

  int ans=lcm;
  while(1){
    if(ans>=n) break;
    ans+=lcm;
  }

  printf("%d\n", ans);

  return 0;
}
