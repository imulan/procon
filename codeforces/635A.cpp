#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i,j;

  int r,c,n,k;
  cin >>r >>c >>n >>k;

  int p[10][10]={0};
  rep(i,n){
    int x,y;
    cin >>x >>y;
    --x; --y;
    p[x][y]=1;
  }

  /*
  rep(i,r){
    rep(j,c) printf(" %d", p[i][j]);
    printf("\n");
  }
  */
  
  long ans=0;
  //上下左右を決めて
  for(int t=0; t<r; ++t){
    for(int b=t; b<r; ++b){
      for(int l=0; l<c; ++l){
        for(int r=l; r<c; ++r){
          //printf("%d %d %d %d\n",t,b,l,r);
          int ct=0;
          for(i=t;i<=b;++i){
            for(j=l;j<=r;++j){
              ct+=p[i][j];
            }
          }
          if(ct>=k) ++ans;
        }
      }
    }
  }


  std::cout << ans << std::endl;
  return 0;
}
