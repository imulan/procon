#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  int n;
  string s;

  cin >> n;
  cin >> s;

  int ans=0;

  int now=0; //文字列の注目位置
  int sh=0, ne=0; //分解されたシャリとネタの数

  while(1){
    if(now>=2*n-2) break;

    if(s[now]=='0' && s[now+1]=='1'){ //普通に積む
      now+=2;
    }
    else if(s[now]=='1' && s[now+1]=='0'){ //ひっくり返して積む
      now+=2;
    }
    else{
      //printf("bunkai %d\n", now );
      if(s[now]=='0'){ //シャリ
        if(sh==0){
          ans++;
          sh++;
          ne++;
        }
        sh--;
        now++;
      }
      else{ //ネタ
        if(ne==0){
          ans++;
          sh++;
          ne++;
        }
        ne--;
        now++;
      }
    }

  }

  printf("%d\n", ans);
}
