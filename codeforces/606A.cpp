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
  long a,b,c,x,y,z;
  cin >>a >>b >>c;
  cin >>x >>y >>z;

  while(a-2>=x){
    if(b<y){
      a-=2;
      b++;
    }
    else if(c<z){
      a-=2;
      c++;
    }
    else break;
  }

  while(b-2>=y){
    if(a<x){
      b-=2;
      a++;
    }
    else if(c<z){
      b-=2;
      c++;
    }
    else break;
  }

  while(c-2>=z){
    if(a<x){
      c-=2;
      a++;
    }
    else if(b<y){
      c-=2;
      b++;
    }
    else break;
  }

  //printf(" %d, %d, %d\n",a, b,c);

  if(a>=x && b>=y && c>=z) printf("Yes\n");
  else printf("No\n");

  return 0;
}
