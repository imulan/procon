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
  int n,d,k;
  std::cin >>n >>d >>k;

  std::vector<int> v(k);
  int sum=0;
  REP(i,k){
    v[i]=i+1;
    sum+=v[i];
  }

  if(sum>d){
    printf("-1\n");
  }
  else{
    for(int i=k-1; i>=0; --i){
      int diff=d-sum;
      int p=n-((k-1)-i);

      if(p-v[i]>=diff){
        v[i]+=diff;
        sum+=diff;
        break;
      }
      else{
        sum+=p-v[i];
        v[i]=p;
      }

    }

    if(sum!=d){printf("-1\n");}
    else{
      for(int i=0; i<k; ++i){
        if(i) printf(" ");
        printf("%d", v[i]);
      }
      printf("\n");
    }
  }

  return 0;
}
