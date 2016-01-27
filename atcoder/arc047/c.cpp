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
  int n,k;
  cin >>n >>k;

  vector<int> p(n);
  REP(i,n) p[i]=i+1;

  ll f=1;
  FOR(i,2,n+1){
    if(i!=k) f*=i;
  }

  ll ct=0;
  vector<int> ans(n);
  do{
    ++ct;

    if(ct==f){
      REP(i,n) ans[i]=p[i];
    }
  }while(next_permutation(p.begin(),p.end()));

  REP(i,n) cout << ans[i] << " ";
  printf("\n");


  //REP(i,n) cout << ans[i] << endl;

  return 0;
}
