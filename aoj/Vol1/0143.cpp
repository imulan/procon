#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef struct{
  int x,y;
}Point;

int det(Point p,Point q){
  return p.x*q.y-p.y*q.x;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  for(int T=0; T<n; ++T){
    int i;

    Point p[3],v,a;
    rep(i,3) scanf(" %d %d", &p[i].x, &p[i].y);
    scanf(" %d %d", &a.x, &a.y);
    scanf(" %d %d", &v.x, &v.y);

    bool _a=false, _v=false;
    int tmp=0;
    rep(i,3){
      Point t1,t2;
      t1.x=p[(i+1)%3].x-p[i].x;
      t1.y=p[(i+1)%3].y-p[i].y;
      t2.x=a.x-p[i].x;
      t2.y=a.y-p[i].y;

      if(det(t1,t2)>0) ++tmp;
      else --tmp;
    }
    if(tmp==3||tmp==-3) _a=true;

    tmp=0;
    rep(i,3){
      Point t1,t2;
      t1.x=p[(i+1)%3].x-p[i].x;
      t1.y=p[(i+1)%3].y-p[i].y;
      t2.x=v.x-p[i].x;
      t2.y=v.y-p[i].y;

      if(det(t1,t2)>0) ++tmp;
      else --tmp;
    }
    if(tmp==3||tmp==-3) _v=true;

    //cout << _a << " " << _v << endl;

    string s="OK";
    if(_a==_v) s="NG";
    std::cout << s << std::endl;
  }
  return 0;
}
