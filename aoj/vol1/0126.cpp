#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  for(int T=0; T<n; ++T){
    int i,j,k;

    int f[9][9];
    rep(i,9)rep(j,9) scanf(" %d", &f[i][j]);

    char tf[9][9];
    rep(i,9){
      rep(j,9){//f[i][j]に対して判定
        bool ok=true;

        //行
        rep(k,9){
          if(j!=k && f[i][j]==f[i][k]) ok=false;
        }

        //列
        rep(k,9){
          if(i!=k && f[i][j]==f[k][j]) ok=false;
        }

        //ブロック
        int sy=3*(i/3), sx=3*(j/3);
        //printf("(%d %d) -> (%d %d)\n",i,j,sy,sx);

        for(int y=sy; y<sy+3; ++y){
          for(int x=sx ; x<sx+3; ++x){
            if(y==i&&x==j) continue;
            if(f[i][j]==f[y][x]) ok=false;
          }
        }

        if(ok) tf[i][j]=' ';
        else tf[i][j]='*';

      }
    }

    if(T) printf("\n");
    rep(i,9){
      rep(j,9){
        printf("%c%d",tf[i][j], f[i][j]);
      }
      printf("\n");
    }

  }
  return 0;
}
