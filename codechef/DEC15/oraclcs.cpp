#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int T;
  cin >>T;
  for(int times=0; times<T; ++times){
    int n;
    cin >>n;

    vector<string> s(n);
    for(int i=0; i<n; ++i) cin >>s[i];

    int ans=0;
    for(int len=s[0],size(); len>0; --len){ //部分列の長さ
      for(int i=0; i<s[0].size()-len+1; ++i){
        string focus = s[0].substr(i,len);
        cout << "focus = " << focus << endl;

      


      }
    }

  }
  return 0;
}
