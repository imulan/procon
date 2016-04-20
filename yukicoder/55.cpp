#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef struct{
  int x,y;
}Point;

int norm(Point p){
  return p.x*p.x+p.y*p.y;
}

int inner(Point p, Point q){
  return p.x*q.x+p.y*q.y;
}

int main(int argc, char const *argv[]) {
  Point p[3];
  rep(i,3) cin >>p[i].x >>p[i].y;

  int dx=p[0].x, dy=p[0].y;
  rep(i,3){
    p[i].x-=dx;
    p[i].y-=dy;
  }

  bool found=false;
  Point ans;
  if(norm(p[1])==norm(p[2])){
    //点1と点2まで距離が等しいなら
    //内積0のとき直角で正方形が存在
    if(inner(p[1],p[2])==0){
      found=true;
      ans.x=p[1].x+p[2].x;
      ans.y=p[1].y+p[2].y;
    }
  }
  else{
    if(norm(p[2])<norm(p[1])) swap(p[1],p[2]);
    //長い方は短い方の2倍
    if(norm(p[1])*2==norm(p[2])){
      if(inner(p[1],p[2])>0){
        if(inner(p[1],p[2])*inner(p[1],p[2])*2 == norm(p[1])*norm(p[2])){
          found=true;
          ans.x=p[2].x-p[1].x;
          ans.y=p[2].y-p[1].y;
        }
      }
    }
  }


  if(!found) printf("-1\n");
  else printf("%d %d\n",ans.x+dx, ans.y+dy);
  
  return 0;
}
