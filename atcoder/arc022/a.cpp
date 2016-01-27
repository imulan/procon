#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >>s;

  string a="ICT";
  string b="ict";

  int now=0;
  for(int i=0; i<s.size(); ++i){
    if(s[i]==a[now] || s[i]==b[now]) ++now;
    if(now==3) break;
  }

  string ans="NO";
  if(now==3) ans="YES";

  cout << ans << endl;

  return 0;
}
