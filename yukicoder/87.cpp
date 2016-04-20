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

bool uru(ll y){
  bool ret;

  if(y%4==0){
    if(y%100==0){
      if(y%400==0) ret=true;
      else ret=false;
    }
    else ret=true;
  }
  else ret=false;

  return ret;
}
int main(int argc, char const *argv[]) {
  ll y;
  cin >>y;

  ll r=y-2014;
  r/=400;
  ll ans=r*57;

  ll st=2014+r*400+1;
  //cout<<"st="<<st<<endl;

  int n=3;
  ll before=2014;
  for(ll i=st; i<=y; ++i){
    if(uru(i)) n+=2;
    else n+=1;
    n%=7;

    if(n==3){
      ++ans;
      //cout << " " << i << endl;
      before=i;
    }
  }

  cout << ans << endl;
  return 0;
}
