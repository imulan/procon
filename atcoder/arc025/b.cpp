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
  int i,j,k;

  int h,w;
  int c[100][100];
  cin >>h >>w;

  rep(i,h){
    rep(j,w){
      scanf(" %d",&c[i][j]);
      if((i+j)%2==0) c[i][j]=-c[i][j];
    }
  }

  //i段目のj番目までの部分和
  int yoko[100][101]={0};
  rep(i,h){
    for(j=1; j<=w; ++j)
      yoko[i][j]=yoko[i][j-1]+c[i][j-1];
  }

  /*
  rep(i,h){
    rep(j,w+1) printf("%2d",yoko[i][j]);
    printf("\n");
  }
  */
  
  int ans=0;
  rep(i,w){
    for(j=i+1; j<=w; ++j){
      //printf("%d, %d::\n", i,j);

      vector<int> v(h+1);
      v[0]=0;
      rep(k,h) v[k+1]=v[k]+yoko[k][j]-yoko[k][i];
      //rep(k,h+1) printf("%d\n",v[k]);

      for(int x=0; x<=h; ++x){
        for(int y=x+1; y<=h; ++y){
          if(v[y]-v[x]==0){
            //printf("%d*%d\n",y-x,j-i);
            ans=max(ans,(y-x)*(j-i));
          }
        }
      }

    }
  }

  std::cout << ans << std::endl;
  return 0;
}
