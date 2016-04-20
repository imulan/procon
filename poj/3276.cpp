//蟻本p.139

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i;

  int n;
  scanf(" %d", &n);

  //向き(F:0,B:1)
  int dir[5000];
  rep(i,n){
    char c;
    scanf(" %c", &c);
    if(c=='F') dir[i]=0;
    else dir[i]=1;
  }

  int K=1,M=n;

  for(int k=1; k<=n; ++k){//連続するk頭の牛を反転
    //反転回数
    int m=0;
    //区間[i,i+k-1]は反転したか
    int f[5000]={0};
    //sum of f[i-(k-1)]...f[i-1]
    int s_f=0;

    for(i=0; i<=n-k; ++i){
      //区間[i,i+k-1]を見る
      if((dir[i]+s_f)%2==1){//後ろを向いているのでひっくり返す
        ++m;
        f[i]=1;
      }
      s_f+=f[i];
      if(i-k+1>=0) s_f-=f[i-k+1];
    }

    //残りが前を向いているかチェック
    for(i=n-k+1; i<n; ++i){
      if((dir[i]+s_f)%2==1){//後ろを向いているのでダメ
        m=-1;
        break;
      }
      if(i-k+1>=0) s_f-=f[i-k+1];
    }

    //答えの更新
    if(m>0 && m<M){
      M=m;
      K=k;
    }
  }

  printf("%d %d\n",K,M);
  return 0;
}
