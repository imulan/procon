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
  string a,b;
  cin >>a;
  cin >>b;

  long z[200001]={0}; //bの1文字目からi文字目までの中のゼロの数
  long o[200001]={0};

  z[0]=0;
  o[0]=0;
  for(long i=1; i<=b.size(); ++i){
    z[i]=z[i-1]+(b[i-1]=='0');
    o[i]=o[i-1]+(b[i-1]=='1');
  }

  ll ans=0;
  for(long i=0; i<a.size(); ++i){
    if(a[i]=='0') ans += o[b.size()-a.size()+1+i]-o[i];
    else ans += z[b.size()-a.size()+1+i]-z[i];
    //cout << "i="<< i<<","<< ans  << endl;
  }

  cout << ans << endl;

  return 0;
}
