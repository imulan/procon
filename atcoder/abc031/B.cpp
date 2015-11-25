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
  int L,H;
  int n;

  cin >> L >> H;
  cin >> n;
  for(int i=0; i<n; ++i){
    int a;
    cin >> a;

    if(a<L) printf("%d\n",L-a);
    else if(a<=H) printf("0\n");
    else printf("-1\n");
  }

}
