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
  int n,bx;
  cin >> n >> bx;

  ll pbx[10]={0};
  pbx[0]=1;
  for(int i=1; i<10; ++i) pbx[i] = pbx[i-1]*bx;

  ll x=0;
  for(int i=n-1; i>=0; --i){
    int a;
    cin >> a;
    x += pbx[i]*a;
  }

  int m,by;
  cin >> m >> by;

  ll pby[10]={0};
  pby[0]=1;
  for(int i=1; i<10; ++i) pby[i] = pby[i-1]*by;

  ll y=0;
  for(int i=m-1; i>=0; --i){
    int a;
    cin >> a;
    y += pby[i]*a;
  }

  //cout << x << " " << y <<endl;

  string ans;
  if(x<y) ans="<";
  else if(x>y) ans=">";
  else ans="=";
  cout << ans << endl;
}
