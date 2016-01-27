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

bool samenum(int p){
  int tmp=p;
  int size=0;
  while(tmp>0){
    tmp/=10;
    size++;
  }

  bool ret=true;
  tmp = p;
  int b=p%10;
  for(int i=0; i<size; ++i){
    if(tmp%10 != b){
      ret=false;
    }
    tmp/=10;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  int ct=0;
  int ans=1;
  while (1) {
    if(samenum(ans)){
      ct++;
    }

    if(ct==n) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
