#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  vector<string> s(n);

  for(int i=0; i<n; ++i){
    cin >>s[i];
    reverse(s[i].begin(),s[i].end());
  }

  sort(s.begin(),s.end());

  for(int i=0; i<n; ++i){
    reverse(s[i].begin(),s[i].end());
    cout << s[i] << endl;
  }

  return 0;
}
