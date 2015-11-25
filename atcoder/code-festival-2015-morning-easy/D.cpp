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

bool sq(string t){
  bool ret;
  if(t.size()%2!=0) ret=false;
  else{
    ret=true;
    for(int i=0; i<t.size()/2; ++i){
      if(t[i] != t[i+t.size()/2]) ret=false;
    }
  }
  return ret;
}

int main(){
  int n;
  string s;

  cin >> n;
  cin >> s;

  for(int i=1; i<s.size()-1; ++i){
    string a = s.substr(0,i);
    string b = s.substr(i);

    //LCS
    int ans=0;
    int dp[100][100];

  }





}
