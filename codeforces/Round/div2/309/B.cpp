#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int n;
  char f[101][101];

  scanf(" %d", &n);
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      scanf(" %c", &f[i][j]);
    }
  }

  int ans=0;
  for(int i=0; i<n; ++i){ //i行目に注目してi行目を全て1にするように塗ってみる

    //copy
    char t[101][101];
    for(int a=0; a<n; ++a)
    for(int b=0; b<n; ++b)
    t[a][b]=f[a][b];

    for(int j=0; j<n; ++j){
      if(t[i][j]=='0'){
        for(int k=0; k<n; ++k){
          if(t[k][j]=='0') t[k][j]='1';
          else t[k][j]='0';
        }
      }
    }

    int tmp=0;
    for(int j=0; j<n; ++j){//行ごとに調べる
      bool ok=true;
      for(int k=0; k<n; ++k){
        if(t[j][k]=='0'){
          ok=false;
          break;
        }
      }

      if(ok) tmp++;
    }

    if(ans<tmp) ans=tmp;
  }

  printf("%d\n", ans);
}
