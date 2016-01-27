#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int t[100][100]={0};

  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i){
    int x1, y1, x2, y2;
    scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--;
    x2--; y2--;

    for(int j=x1; j<=x2; ++j){
      for(int k=y1; k<=y2; ++k){
        t[j][k]++;
      }
    }

  }

  int ans=0;
  for(int i=0; i<100; ++i){
    for(int j=0; j<100; ++j){
      ans += t[i][j];
    }
  }

  printf("%d\n", ans);
}
