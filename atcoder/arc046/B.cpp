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
  int n,a,b;
  cin >>n;
  cin >>a >>b;

  if(a==b){
    int p=a+1;
    if(n%p==0) printf("Aoki\n");
    else printf("Takahashi\n");
  }
  else{
    if(n<=a) printf("Takahashi\n");
    else{
      if(a>b) printf("Takahashi\n");
      else printf("Aoki\n");
    }
  }

  return 0;
}
