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

int main(int argc, char const *argv[]) {
  int x,y,x0,y0;
  string s;

  cin >>x >>y >>x0 >>y0;
  cin >>s;

  int visit[501][501]={0};
  long ct=0;

  //その場に爆弾があるとき
  printf("1 ");
  ct++;
  visit[x0][y0]=1;

  for(long k=0; k<s.size()-1; ++k){
    if(s[k] == 'L') y0=max(1,y0-1);
    else if(s[k] == 'R') y0=min(y,y0+1);
    else if(s[k] == 'U') x0=max(1,x0-1);
    else if(s[k] == 'D') x0=min(x,x0+1);
    //printf("%d, %d\n", x0, y0);
    if(visit[x0][y0]==0){
      visit[x0][y0]=1;
      ct++;
      printf("1 ");
    }
    else printf("0 ");
  }
  printf("%ld\n", (long)x*y-ct);

  return 0;
}
