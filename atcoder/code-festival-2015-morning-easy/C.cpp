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
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  long n,k,m,r;
  scanf(" %ld %ld %ld %ld", &n, &k, &m, &r);

  long s[102]={0};
  for(long i=0; i<n-1; ++i) scanf(" %ld", &s[i]);
  sort(s,s+(n-1),greater<long>());
  //for(int i=0; i<n-1; ++i) printf(" %ld\n", s[i]);

  long sum=0;
  for(long i=0; i<((k<n)?k:n); ++i) sum+=s[i];

  long ans;
  if(k<n){
    if(sum-s[k-1]+m<r*k) ans=-1;
    else if(sum >= r*k) ans=0;
    else{
      long tmp = r*k-sum+s[k-1];
      if(0<=tmp && tmp<=m) ans=tmp;
      else if(tmp<0) ans=0;
      else ans=-1;
    }
  }
  else{
    long tmp=r*k-sum;
    if(0<=tmp && tmp<=m) ans=tmp;
    else if(tmp<0) ans=0;
    else ans=-1;
  }
  printf("%ld\n", ans);
}
