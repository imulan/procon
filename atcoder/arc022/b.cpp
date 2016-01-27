#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  int a[100000];

  scanf(" %d", &n);
  for(int i=0; i<n; ++i) scanf(" %d", &a[i]);

  //今注目している区間でその味を食べているか
  int eat[100001]={0};
  int ans=1;
  int st=0; //区間の左端
  for(int i=0; i<n; ++i){
    if(eat[a[i]]>0){
      ans = max(ans, i-st);
      while(eat[a[i]]>0){
        --eat[a[st]];
        ++st;
      }
    }

    ++eat[a[i]];
  }
  ans=max(ans, n-st);

  printf("%d\n", ans);

  return 0;
}
