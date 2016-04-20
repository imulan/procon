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

bool ch(long n){
  if(n%3==0) return true;

  while(n>0){
    if(n%10==3) return true;
    n/=10;
  }

  return false;
}

int main(int argc, char const *argv[]) {
  long a,b;
  cin >>a >>b;

  for(long i=a; i<=b; ++i){
    if(ch(i)) printf("%ld\n", i);
  }
  return 0;
}
