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
  int n;
  string s;

  cin >> n;
  cin >> s;

  if(n%2!=0) printf("-1\n");
  else{
    int ans=0;
    for(int i=0; i<s.size()/2; ++i){
      if(s[i] != s[i+s.size()/2]) ans++;
    }

    printf("%d\n", ans);
  }

}
