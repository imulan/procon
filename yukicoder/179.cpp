#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int h,w;
  cin >>h >>w;
  std::vector<string> s(h);
  rep(i,h) cin >>s[i];

  int num=0;
  rep(i,h){
    rep(j,w){
      num+=(s[i][j]=='#');
    }
  }

  string ans="NO";

  if(num>0&&num%2==0){
    bool valid=false;

    for(int y=-(h-1); y<=h-1; ++y){//縦の平行移動幅
      for(int x=-(w-1); x<=w-1; ++x){//横の平行移動幅

        //printf("x,y=%d %d\n",x,y);

        int f[50][50]={0};
        int ct=0;
        rep(i,h){
          rep(j,w){

            if(0<=i+y&&i+y<h&&0<=j+x&&j+x<w){
              if(s[i][j]=='#'&&s[i+y][j+x]=='#'){
                if(f[i][j]==0&&f[i+y][j+x]==0){
                  /*
                  printf(" (%d, %d) ->",i,j);
                  printf(" (%d, %d)\n",i+y,j+x);
                  */
                  f[i][j]=1;
                  f[i+y][j+x]=2;
                  ++ct;
                }
              }
            }

          }
        }


        if(ct==num/2){
          valid=true;
          break;
        }
      }
      if(valid) break;
    }

    if(valid) ans="YES";
  }

  std::cout << ans << std::endl;
  return 0;
}
