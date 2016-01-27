#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  double ans=0;

  cin >>n;
  for(int i=0; i<n; ++i){
    char r;
    scanf(" %c", &r);
    if(r=='A') ans+=4;
    else if(r=='B') ans+=3;
    else if(r=='C') ans+=2;
    else if(r=='D') ans+=1;
  }

  printf("%.20lf\n", ans/n);
  return 0;
}
