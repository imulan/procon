#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string aa,bb;
  cin >>aa >>bb;

  int a[3], b[3];
  for(int i=0; i<3; ++i){
    a[i]=aa[i]-'0';
    b[i]=bb[i]-'0';
  }

  int pw[3]={100,10,1};

  int ans=0;
  //まずどこもいじらない場合を計算
  for(int i=0; i<3; ++i) ans+=(a[i]-b[i])*pw[i];

  //aの9じゃない最上位の桁を9にする
  for(int i=0; i<3; ++i){
    if(a[i]!=9){
      int tmp=0;
      for(int j=0; j<3; ++j){
        if(i==j) tmp+=9*pw[j];
        else tmp+=a[j]*pw[j];

        tmp-=b[j]*pw[j];
      }

      ans=max(ans,tmp);
      break;
    }
  }

  //bの最上位を1にする、最上位が1ならそれ以下のところで最上位の0で無い所を0にする
  if(b[0]==1){
    for(int i=1; i<3; ++i){
      if(b[i]!=0){
        int tmp=0;
        for(int j=0; j<3; ++j){
          tmp+=a[j]*pw[j];

          if(i!=j) tmp-=b[j]*pw[j];
        }

        ans=max(ans,tmp);
        break;
      }
    }
  }
  else{
    int tmp=0;
    tmp+=(a[0]-1)*100;
    for(int i=1; i<3; ++i) tmp+=(a[i]-b[i])*pw[i];
    ans=max(ans,tmp);
  }


  printf("%d\n",ans);
  return 0;
}
