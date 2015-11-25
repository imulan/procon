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
  string s;
  int num[520]={0};

  int a[6][520]={0};
  /*
  0 なにもしない
  1 -
  2 !
  3 -!
  4 !!
  5 -!!
  */

  cin >> s;

  for(int i=-256; i<=256; ++i){
    num[i+256] = i;
    for(int j=0; j<6; ++j) a[j][i+256]=i;
  }

  for(int i=-256; i<=256; ++i){
    a[1][i+256] = - a[1][i+256];
    a[2][i+256] = !a[2][i+256];

    a[3][i+256] = !a[3][i+256];
    a[3][i+256] = -a[3][i+256];

    a[4][i+256] = !a[4][i+256];
    a[4][i+256] = !a[4][i+256];

    a[5][i+256] = !a[5][i+256];
    a[5][i+256] = !a[5][i+256];
    a[5][i+256] = -a[5][i+256];
  }


  for(int p=s.size()-1; p>=0; --p){
    if(s[p]=='-'){
      for(int i=-256; i<=256; ++i) num[i+256] = -num[i+256];
    }
    else if(s[p]=='!'){
      for(int i=-256; i<=256; ++i) num[i+256] = !num[i+256];
    }
  }

  int ans=-1;
  for(int j=0; j<6; ++j){
    bool match=true;

    for(int i=-256; i<=256; ++i){
      if(num[i+256] != a[j][i+256]){
        match=false;
        break;
      }
    }

    if(match){
      ans=j;
      break;
    }
  }

  if(ans==0) printf("\n");
  else if(ans==1) printf("-\n");
  else if(ans==2) printf("!\n");
  else if(ans==3) printf("-!\n");
  else if(ans==4) printf("!!\n");
  else if(ans==5) printf("-!!\n");
  else printf("NOTFOUND\n");
}
