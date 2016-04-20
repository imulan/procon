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
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  vector<int> ans(n);
  bool found=false;

  REP(i,n){
    int ct[51]={0};
    REP(j,n){
      int a;
      scanf(" %d", &a);
      ++ct[a];
    }

    int L=0;
    for(int j=1; j<=n; ++j){
      if(ct[j]>0) L=j;
    }

    if(L==n-1){
      if(!found){
        ans[i]=n-1;
        found=true;
      }
      else ans[i]=n;
    }
    else ans[i]=L;
  }


  REP(i,n){
    if(i>0) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");

  return 0;
}
