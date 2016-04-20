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
  std::vector<int> a(n);

  int sum=0;
  REP(i,n){
    cin >>a[i];
    sum+=a[i];
  }

  sum/=(n-1);

  int t=0,k=0;
  REP(i,n){
    if(sum-a[i]==2) ++t;
    else ++k;
  }

  printf("%d %d\n",t,k);
  return 0;
}
