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

long isBeautiful(string a){
  long ret=0;

  if(a=="1") ret=0;
  else{
    if(a[0]!='1') ret=-1;
    else{
      for(int i=1; i<a.size(); ++i){
        if(a[i]!='0'){
          ret=-1;
          break;
        }
        ret=i;
      }
    }
  }
  //cout << a << " : " << ret << endl;
  return ret;
}

int main(int argc, char const *argv[]) {
  long n;
  cin >>n;

  bool z=false;

  string notb="x";
  long zeros=0;

  for(long i=0; i<n; ++i){
    string s;
    cin >>s;

    if(s=="0") z=true;
    int r=isBeautiful(s);

    if(r==-1) notb=s;
    else{
      if(i==n-1 && notb=="x"){
        notb=s;
      }
      else zeros+=r;
    }
  }

  if(z) printf("0\n");
  else{
    cout << notb;
    for(long i=0; i<zeros; ++i) printf("0");
    cout << endl;
  }


  return 0;
}
