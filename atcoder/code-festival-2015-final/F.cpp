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

const int mod = 1e9+7;

int n;
int c[256];

int rec(int prev, int next, int dir){ //前にいた場所、次に向かう場所、直前の操作で戻ったのか(0)深くしたのか(1)

  int ret=0;



}

int main(){
  cin >> n;
  for(int i=0; i<n; ++i) scanf(" %d", &c[i]);

  if(c[0]!=1) printf("0\n");
  else printf("%d\n", rec(c[i],c[i+1],-1));

}
