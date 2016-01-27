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
  int x;
  string of, t;

  cin >>x;
  cin >>of;
  cin >>t;

  int ans=-1;
  if(t=="week"){
    if(x==5 || x==6) ans=53;
    else ans=52;
  }
  else{
    if(x<=29) ans=12;
    else if(x==30) ans=11;
    else ans=7;
  }

  cout << ans << endl;

  return 0;
}
