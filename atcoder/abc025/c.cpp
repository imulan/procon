#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int b[6], c[6];

int rec(int f[9]){

  int nf[9];
  int z=0;
  for(int i=0; i<9; ++i){
    nf[i]=f[i];
    if(f[i]!=0) ++z;
  }

  int ret=0;
  if(z==9){ //ゲーム終了
    for(int i=0; i<6; ++i){
      if(f[i]==f[i+3]) ret+=b[i];
    }

    int ct=0;
    for(int i=0; i<8; ++i){
      if(i%3==2) continue;
      if(f[i]==f[i+1]) ret+=c[ct];
      ++ct;
    }
    /*
    printf("now answer: %d\n", ret);
    for(int i=0; i<9; ++i){
      printf("%d",f[i]);
      if(i%3==2) printf("\n");
    }
    */
  }
  else{
    if(z%2==0){ //先手
      //最大化するように選ぶ
      for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j) nf[j]=f[j];

        if(nf[i]!=0) continue;

        nf[i]=1;
        ret=max(ret, rec(nf));
      }

    }
    else{ //後手
      //最小化するように選ぶ
      ret=2000;
      for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j) nf[j]=f[j];

        if(nf[i]!=0) continue;
        nf[i]=2;
        ret=min(ret, rec(nf));
      }
    }

  }

  return ret;
}

int main(int argc, char const *argv[]) {
  int sum=0;
  for(int i=0; i<6; ++i) cin >>b[i];
  for(int i=0; i<6; ++i) cin >>c[i];
  for(int i=0; i<6; ++i) sum+=b[i]+c[i];

  int st[9]={0};
  int ans=rec(st);

  printf("%d\n%d\n", ans, sum-ans);

  return 0;
}
