#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  int n;
  string s;
  int ct=0;

  string t="b";
  char a[4]="acb", b[4]="cab"; //after,before

  scanf(" %d", &n);
  cin >> s;

  while(ct<n){
    if(t==s) break;
    t = a[ct%3] + t + b[ct%3];
    //cout << t << endl;
    ct++;
  }

  if(t!=s) ct=-1;
  printf("%d\n", ct);
}
