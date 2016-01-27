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

  std::vector<int> L(n);
  std::vector<int> k(n-1);
  REP(i,n-1) scanf(" %d", &k[i]);

  L[0]=k[0];
  L[n-1]=k[n-2];

  for(int i=1; i<=n-2; ++i){
    L[i]=min(k[i-1],k[i]);
  }

  REP(i,n){
    if(i!=0) printf(" ");
    printf("%d", L[i]);
  }
  printf("\n");
  return 0;
}
