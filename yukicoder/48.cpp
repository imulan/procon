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
  int x,y,L;
  cin >>x >>y >>L;

  long ans=0;
  if(x!=0){
    ++ans;
    if(y<0) ++ans;
  }
  else{
    if(y<0) ans+=2;
  }

  if(x<0) x=-x;
  if(y<0) y=-y;

  ans+=x/L+y/L;

  if(x%L!=0) ++ans;
  if(y%L!=0) ++ans;

  cout << ans << endl;
  return 0;
}
