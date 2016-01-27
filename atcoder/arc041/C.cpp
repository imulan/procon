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


int main(int argc, char const *argv[]) {
  int N,L;
  cin >>N >>L;

  vector<int> x(N);
  vector<char> d(N);

  //i番目の区間で、(Rの出現数,Lの出現数)
  int ct[100000][2]={0};
  int ct_index=0;

  //今は左向きのうさぎを観測する区域か
  bool left=true;

  REP(i,N){
    scanf(" %d %c", &x[i], &d[i]);

    if(left){ //左向きのうさぎを観測すべき区域
      if(d[i]=='L'){
        ++ct[ct_index][1];
      }
      else{
        ++ct_index;
        ++ct[ct_index][0];
        left=false;
      }
    }
    else{
      if(d[i]=='R'){
        ++ct[ct_index][0];
      }
      else{
        ++ct[ct_index][1];
        left=true;
      }
    }
  }

  long ans=0;
  int now=-1; //見終わったindex
  REP(i, ct_index+1){
    //printf("kukan %d: R %d, L %d\n", i, ct[i][0], ct[i][1]);

    int base;
    //左向きのウサギの方が多いので、左に詰める
    if(ct[i][0]<=ct[i][1]){
      //indexを見る
      base=now+ct[i][0];
      //座標を入れる
      if(base==-1) base=0; //左端
      else base=x[base];

      int gap=1;
      //右に詰める
      for(int j=now+ct[i][0]-1; j>=now+1; --j){
        ans+=(base-gap)-x[j];
        ++gap;
      }

      gap=1;
      now=now+ct[i][0];
      //左に詰める
      for(int j=now+1; j<=now+ct[i][1]; ++j){
        ans+=x[j]-(base+gap);
        ++gap;
      }
      now=now+ct[i][1];
    }
    else{ //右に詰める
      //indexを見る
      base=now+ct[i][0]+1;
      //座標を入れる
      if(base==N) base=L+1; //右端
      else base=x[base];
      int gap=1;

      //右に詰める
      for(int j=now+ct[i][0]; j>=now+1; --j){
        ans+=(base-gap)-x[j];
        ++gap;
      }

      gap=1;
      now=now+ct[i][0]+1;
      //左に詰める
      for(int j=now+1; j<=now+ct[i][1]-1; ++j){
        ans+=x[j]-(base+gap);
        ++gap;
      }
      now=now+ct[i][1]-1;

    }

  }

  printf("%ld\n", ans);

  return 0;
}
