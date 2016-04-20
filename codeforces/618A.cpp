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
  long n;
  cin >>n;

  vector<long> ans;

  for(long i=18; i>=0; --i){
    if((n>>i)&1){
      ans.push_back(i+1);
    }
  }

  //printf("%d\n", ans.size());
  for(long i=0; i<ans.size(); ++i){
    if(i>0) printf(" ");
    printf("%ld",ans[i]);
  }
  printf("\n");
  return 0;
}
