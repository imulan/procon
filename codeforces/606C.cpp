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
#include <iterator>
using namespace std;

typedef long long ll;
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(int argc, char const *argv[]) {
  long n;
  cin >> n;
  vector<long> p(n);
  vector<long> pos(n+1);
  for(long i=0; i<n; ++i){
    scanf(" %ld", &p[i]);
    pos[p[i]] = i;
  }

  //しゃくとり法
  long st=0;
  long val=-1;
  long ans=1;
  for(long i=1; i<=n; ++i){
    if(val<pos[i]){ //のばせる
      val = pos[i];
    }
    else{ //1個手前までの長さをチェック
      ans = max(ans, i-st-1);
      st=i-1;
      val=pos[i];
    }
    //cout << "st=" << st  << " , ans = " << ans <<endl;
  }
  ans = max(ans, n-st);

  cout << n-ans <<endl;
  return 0;
}
