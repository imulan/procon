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

  std::vector<int> sp(n);
  REP(i,n){
    int a,b;
    scanf(" %d %d", &a, &b);
    sp[i]=a+4*b;
  }

  sort(sp.begin(),sp.end());

  bool valid=true;
  long ans=0;
  REP(i,n-1){
    int t=sp[n-1]-sp[i];

    if(t%2!=0){
      valid=false;
      break;
    }
    else ans+=t/2;
  }

  if(valid) printf("%ld\n", ans);
  else printf("-1\n");

  return 0;
}
