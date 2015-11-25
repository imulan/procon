#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int a;
  scanf(" %d", &a);

  int ans=0;
  for(int x=1; x<a; ++x){
    int tmp=x*(a-x);
    if(tmp>ans) ans=tmp;
  }

  printf("%d\n", ans);
}
