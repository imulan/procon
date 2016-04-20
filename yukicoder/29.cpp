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

  int item[11]={0};
  REP(i,n){
    int a,b,c;
    cin >>a >>b >>c;
    ++item[a];
    ++item[b];
    ++item[c];
  }

  int ans=0;
  int tmp=0;
  for(int i=1; i<=10; ++i){ //同じアイテム2個
    ans+=item[i]/2;
    item[i]-=(item[i]/2)*2;
    if(item[i]==1) ++tmp;
  }
  ans+=tmp/4;

  std::cout << ans << std::endl;
  return 0;
}
