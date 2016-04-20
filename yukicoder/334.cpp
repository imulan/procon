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

bool ch(int x, int y, int z){
  bool ret=true;
  if(x==y || x==z || y==z) ret=false;
  else{
    if(x<y && y<z) ret=false;
    if(x>y && y>z) ret=false;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  int n;
  int k[12];

  cin >>n;
  REP(i,n) cin >>k[i];

  //状態をbitで表し、この状態で自分の番が来たら勝てるのか
  bool w[4100];
  w[0]=false;

  FOR(st,1,1<<n){ //状態stのとき
    int ones=0;
    //立ってるbitが2つ以下なら負け確定
    REP(i,n) ones+=(st>>i)&1;

    //printf(" %d : %d\n", st, ones);
    if(ones<3){
      w[st]=false;
    }
    else{
      //bitが立ってる位置はまだ場に残っている
      //3重ループで列挙
      //どう選んでも勝ちの状態に行くならそこは負け
      //1つでも負けの状態に行く道があればそこは勝ち
      w[st]=false;
      FOR(a,0,n)FOR(b,a+1,n)FOR(c,b+1,n){
        //3つを列挙
        if((st>>a)&1 && (st>>b)&1 && (st>>c)&1){
          //全てbitが立ってれば試せる
          if(ch(k[a],k[b],k[c])){ //門松数？
            int nx=st-(1<<a)-(1<<b)-(1<<c);

            if(!w[nx]){
              w[st]=true;
              break;
            }
          }

        }
      }
    }

    //cout << st << " : " << w[st] << endl;
  }

  if(!w[(1<<n)-1]) printf("-1\n");
  else{
    //勝てる方法があるので小さい方から試して見つかったら終わり

    int aa,bb,cc;
    bool find=false;
    FOR(a,0,n){
      FOR(b,a+1,n){
        FOR(c,b+1,n){
          if(ch(k[a],k[b],k[c])){ //門松数？
            if(!w[(1<<n)-1-(1<<a)-(1<<b)-(1<<c)]){
              aa=a;
              bb=b;
              cc=c;
              find=true;
              break;
            }
          }
        }
        if(find) break;
      }
      if(find) break;
    }

    printf("%d %d %d\n",aa,bb,cc);
  }

  return 0;
}
