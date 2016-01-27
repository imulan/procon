#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int cycle(int x){
  int ret=0;

  while(1){
    ++ret;
    //printf(" %d", x);
    if(x==1) break;

    if(x%2==1) x=3*x+1;
    else x=x/2;
  }
  //printf("\n");
  return ret;
}

int main(int argc, char const *argv[]) {
  int i,j;
  while(scanf(" %d %d", &i,&j)!=EOF){
    int m=0;
    for(int a=min(i,j); a<=max(i,j); ++a){
      m=max(m,cycle(a));
    }
    printf("%d %d %d\n",i,j,m);
  }
  return 0;
}
