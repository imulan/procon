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
  ll L,R,k;
  cin >>L >>R >>k;

  ll p[61]={0};
  p[0]=1;

  int lim;
  for(int i=0; i<60; ++i){
    if(p[i]>R/k+1) break;

    p[i+1]=p[i]*k;
    lim=i+1;

    //cout <<p[i] <<endl;

    if(p[i+1]>R) break;
  }

  int ct=0;
  for(int i=0; i<=lim; ++i){
    if(L<=p[i]&&p[i]<=R){
      if(ct>0) printf(" ");
      cout << p[i];
      ++ct;
    }
  }

  if(ct==0) printf("-1");

  cout << endl;

  return 0;
}
