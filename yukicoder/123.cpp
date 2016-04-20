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

int main(int argc, char const *argv[]) {
  int n,m;
  cin >>n >>m;

  std::vector<int> a(m);
  REP(i,m) scanf(" %d", &a[i]);

  int pos=1; //最終的に１番上にある
  //はじめはどこにあったのかを逆順走査で見つけに行く
  for(int i=m-1; i>=0; --i){
    if(pos==1){ //この時点で１番上にあるということは
      //このターンで上に持ってこられたということ。
      pos = a[i];
    }
    else{
      if(pos<=a[i]){ //このターンで一番上に来るカードがposより下にある時
        --pos; //元々は1つ上にいた
      }
    }
  }
  std::cout << pos << std::endl;
  return 0;
}
