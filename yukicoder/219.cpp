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
  for(int t=0; t<n; ++t){
    long a,b;
    cin >>a >>b;

    double pw[33]={0};
    ll n10[33]={0};

    pw[0]=a;
    while(pw[0]>=10){
      pw[0]/=10;
      ++n10[0];
    }


    for(int i=1; i<=32; ++i){
      pw[i]=pw[i-1]*pw[i-1];
      n10[i]=2*n10[i-1];
      while(pw[i]>=10){
        pw[i]/=10;
        ++n10[i];
      }
    }

    /*
    for(int i=0; i<=32; ++i){
      printf("%.3lf %lld\n",pw[i], n10[i]);
    }
    */
    double p=1.0;
    ll ct=0;
    for(int i=0; i<32; ++i){
      if((b>>i)&1){
        p*=pw[i];
        ct+=n10[i];
      }
    }

    while(p>=10){
      p/=10;
      ++ct;
    }

    p*=10;
    int pp=(int)p;

    printf("%d %d %lld\n",pp/10,pp%10,ct);
  }
  return 0;
}
