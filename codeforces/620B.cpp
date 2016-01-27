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
  long a,b;
  cin >>a >>b;

  long seg[10]={6,2,5,5,4,5,6,3,7,6};
  long ans=0;
  for(long i=a; i<=b; ++i){
    long tmp=i;
    while(tmp!=0){
      ans+=seg[tmp%10];
      tmp/=10;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
