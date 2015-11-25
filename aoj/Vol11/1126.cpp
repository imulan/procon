#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

//string型で表す整数の大小比較
//x>y :1, x<y:-1, x=y:0
int cmp(string x, string y){
  int ret=0;
  if(x==y) ret=0;
  else{
    if(x.size() > y.size()) ret=1;
    else if(x.size() < y.size()) ret=-1;
    else{
      for(int i=0; i<x.size(); ++i){
        if(x[i]!=y[i]){
          if(x[i]>y[i]) ret=1;
          else ret=-1;
          break;
        }
      }
    }
  }
  return ret;
}

bool isNum(char c){
  return ('0'<=c && c<='9');
}

int main(){
  while(1){
    int w, h;
    cin>>w>>h;
    if(w==0 && h==0) break;

    char c[72][72];
    for(int i=1; i<=h; ++i)
    for(int j=1; j<=w; ++j)
    scanf(" %c", &c[i][j]);

    for(int i=0; i<=w; ++i) c[0][i]='0';
    for(int i=0; i<=h; ++i) c[i][0]='0';

    string dp[71][71];
    for(int i=0; i<=h; ++i){
      for(int j=0; j<=w; ++j){
        dp[i][j]="0";
      }
    }

    for(int i=1; i<=h; ++i){
      for(int j=1; j<=w; ++j){
        if(isNum(c[i][j])){
          string p=dp[i-1][j];
          string q=dp[i][j-1];

          if(p=="0") p=c[i][j];
          else p+=c[i][j];
          if(q=="0") q=c[i][j];
          else q+=c[i][j];

          if(cmp(p,q)==1) dp[i][j]=p;
          else dp[i][j]=q;
        }
      }
    }

    string ans="0";
    for(int i=1; i<=h; ++i){
      for(int j=1; j<=w; ++j){
        if(cmp(ans,dp[i][j])==-1) ans=dp[i][j];
      }
    }
    cout << ans << endl;
  }
}
