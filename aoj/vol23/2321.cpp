#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct{
  int m; //スケジュールをビットで持つ
  long L;
}guy;

int n;
guy g[100];

long dp[101][65537]; //2^16+1
//今x人目に注目していて、yのスケジュール状態での満足度の最大値
long rec(int x, int y){
  if(dp[x][y]>=0) return dp[x][y];

  if(x==n) return 0;

  long ret=0;

  //x人目のスケジュール状態と今の状態yを比較
  if((g[x].m & y)==0){
    //両方のビットが同時に立つビットがない
    //x人目とデートするかしないかの選択権がある
    ret = max( rec(x+1,y), rec(x+1,y|g[x].m)+g[x].L );
  }
  else ret = rec(x+1,y);

  return dp[x][y] = ret;
}

int main(){
  while (1) {
    //input
    cin >> n;
    if(n==0) break;
    for(int i=0; i<n; ++i){
      int p;
      cin >> p >> g[i].L;
      g[i].m=0;
      for(int j=0; j<p; ++j){
        int s,e;
        cin >> s >> e;
        for(int k=s; k<e; ++k) g[i].m += (1<<(k-6));
      }
    }

    //solve
    memset(dp, -1, sizeof(dp));
    cout << rec(0,0) << endl;
  }
}
