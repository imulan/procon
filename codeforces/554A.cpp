#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;

  int ct[26]={0};
  for(int i=0; i<s.size(); ++i) ct[s[i]-'a']++;

  int ans=0;
  for(int i=0; i<26; ++i) ans+=s.size()+1-ct[i];

  printf("%d\n", ans);
}
