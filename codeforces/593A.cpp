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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

int main(){
  int n;
  string s[100];

  cin >> n;
  REP(i,n) cin>>s[i];

  bool use[100][26];
  bool ok[100];

  REP(i,100){
    REP(j,26){
      use[i][j]=false;
    }
  }

  //まず使われている文字をカウント
  REP(i,n){
    REP(j,s[i].size()){
      use[i][s[i][j]-'a']=true;
    }

    int ct=0;
    REP(j,26){
      ct+=use[i][j];
    }
    if(ct<=2) ok[i]=true;
    else ok[i]=false;
  }

  int ans=0;
  //使う2文字を選ぶ
  FOR(i,0,26){
    FOR(j,i+1,26){
      int tmp=0;

      //使う2文字に対してn個のタイトルが妥当かどうか、妥当なら加える
      REP(p,n){
        if(!ok[p]) continue;

        bool x=true;
        REP(k,26){
          if(k==i || k==j) continue;
          if(use[p][k]) x=false;
        }

        if(x) tmp+=s[p].size();
      }

      ans=max(ans,tmp);
    }
  }


  printf("%d\n", ans);
}
