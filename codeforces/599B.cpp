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
  long n,m;
  long f[100001], finv[100001]={0}, a[100001]={0};

  bool amb[100001];
  for(long i=0; i<=100000; ++i) amb[i]=false;

  bool imp=false;
  bool ambiguity=false;

  cin >> n >> m;
  for(long i=1; i<=n; ++i){
    scanf(" %ld", &f[i]);
    if(finv[f[i]]!=0){
      amb[i]=true;
    }
      finv[f[i]]=i; //逆像
  }

  for(long i=1; i<=m; ++i){
    long b;
    scanf(" %ld", &b);
    a[i]=finv[b];
    //printf(" a[%ld] = %ld\n",i, a[i]);

    if(a[i]==0) imp=true;
    else if(amb[a[i]]) ambiguity=true;
  }

  if(imp) printf("Impossible\n");
  else if(ambiguity) printf("Ambiguity\n");
  else{
    printf("Possible\n");
    for(long i=1; i<=m; ++i){
      if(i>1) printf(" ");
      printf("%ld", a[i]);
    }
    printf("\n");
  }

}
