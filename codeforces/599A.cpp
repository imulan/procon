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
  long d1,d2,d3;

  cin >> d1 >> d2 >> d3;

  long ans=d1+d2+d3;
  ans = min(ans,(d1+d3)*2);
  ans = min(ans,(d2+d3)*2);
  ans = min(ans,(d1+d2)*2);

  cout << ans <<endl;
}
