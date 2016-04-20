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
  string a,b;
  cin >>a >>b;

  int x[26]={0}, y[26]={0};
  REP(i,a.size()){
    ++x[a[i]-'a'];
    ++y[b[i]-'a'];
  }

  bool ok=true;
  REP(i,26){
    if(x[i]!=y[i]) ok=false;
  }

  string ans="NO";
  if(ok) ans="YES";

  std::cout << ans << std::endl;
  return 0;
}
