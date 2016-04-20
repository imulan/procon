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
  string s;
  cin >>s;

  //アルファベットは26文字
  string a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int n=a.size();

  for(int i=0; i<s.size(); ++i){
    int p=i+1; //p文字目

    int now=s[i]-'A';
    now = (now-p+n*1000)%n; //ずらし
    s[i]=a[now];
  }

  std::cout << s << std::endl;
  return 0;
}
