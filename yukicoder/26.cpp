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
  int a[4]={0};
  int n,m;
  cin >>n >>m;
  a[n]=1;
  REP(i,m){
    int p,q;
    scanf("%d %d", &p, &q);
    swap(a[p],a[q]);
  }
  for(int i=1; i<=3; ++i){
    if(a[i]) printf("%d\n", i);
  }
  return 0;
}
