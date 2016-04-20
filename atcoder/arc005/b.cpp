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

  int x,y;
  string w;
  int c[10][10];

  cin >>x >>y >>w;
  rep(i,9)rep(j,9){
    char ch;
    scanf(" %c",&ch);
    c[i+1][j+1]=ch-'0';
  }

  //方向
  int dx=0,dy=0;
  if(w=="R") dx=1;
  else if(w=="L") dx=-1;
  else if(w=="U") dy=-1;
  else if(w=="D") dy=1;
  else if(w=="RU"){dx=1; dy=-1;}
  else if(w=="RD"){dx=1; dy=1;}
  else if(w=="LU"){dx=-1; dy=-1;}
  else if(w=="LD"){dx=-1; dy=1;}

  int ct=0;
  string ans="";
  while(ct<4){
    //printf("%d, %d\n",x,y);
    ans+=c[y][x]+'0';
    int nx=x+dx;
    int ny=y+dy;

    if(nx<=0){
      nx=2;
      dx=-dx;
    }
    if(nx>9){
      nx=8;
      dx=-dx;
    }
    if(ny<=0){
      ny=2;
      dy=-dy;
    }
    if(ny>9){
      ny=8;
      dy=-dy;
    }
    x=nx;
    y=ny;

    ++ct;
  }
  std::cout << ans << std::endl;
  return 0;
}
