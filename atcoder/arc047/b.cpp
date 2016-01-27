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

struct Point{
  long x,y;
};

struct PD{
  double x,y;
};

double t=M_PI/4;
const double q2=sqrt(2);

long cc(double r){
  if(r>=0) return (long)(r+0.01);
  else return (long)(r-0.01);
}

int main(int argc, char const *argv[]) {
  int n;
  cin >>n;

  vector<Point> p(n);
  REP(i,n){
    scanf(" %ld %ld", &p[i].x, &p[i].y);
  }
  /*
  //(y-x, y+x)
  vector< pair<long,long> > v(n);

  REP(i,n){
    scanf(" %ld %ld", &p[i].x, &p[i].y);
    v[i].first = p[i].y-p[i].x;
    v[i].second = p[i].y+p[i].x;
  }
  */
  //check
  /*
  REP(i,n){
    printf("(%ld,%ld) -> <%ld, %ld>\n", p[i].x,p[i].y,v[i].first,v[i].second);
  }
  */

  if(n==1){
    printf("0 0\n");
  }
  else if(n==2){
    printf("%ld %ld\n", p[0].x, p[0].y );
  }
  else{
    vector<PD> v(n);

    double lx=1e15,ly=1e15;
    double rx=-1e15,ry=-1e15;
    REP(i,n){
      double tx=p[i].x*cos(t)-p[i].y*sin(t);
      double ty=p[i].x*sin(t)+p[i].y*cos(t);

      v[i].x=tx*q2; v[i].y=ty*q2;

      lx=min(lx,v[i].x);
      rx=max(rx,v[i].x);
      ly=min(ly,v[i].y);
      ry=max(ry,v[i].y);
      //printf("(%lf,%lf)\n",v[i].x,v[i].y);
    }

    //printf("%lf %lf\n%lf %lf\n",lx,rx,ly,ry);

    double px,py;
    if(cc(rx-lx)==cc(ry-ly)){
      px=(lx+rx)/2.0;
      py=(ly+ry)/2.0;
    }
    else if(cc(rx-lx)>cc(ry-ly)){
      px=(lx+rx)/2.0;

      long y_b=0;
      //1本確定してるyの線を探す
      set<long> yy;
      REP(i,n){
        if(yy.find(cc(v[i].y))==yy.end()){
          yy.insert(cc(v[i].y));
        }
        else{ //見つかった
          y_b=cc(v[i].y);
          break;
        }

      }

      //この線より右か左か探す
      REP(i,n){
        if(cc(v[i].y)<y_b){ //左
          py=y_b-(rx-lx)/2.0;
          break;
        }
        else if(y_b<cc(v[i].y)){ //右
          py=y_b+(rx-lx)/2.0;
          break;
        }
      }

    }
    else{
      py=(ly+ry)/2.0;

      long x_b=0;
      //1本確定してるxの線を探す
      set<long> xx;
      REP(i,n){
        if(xx.find(cc(v[i].x))==xx.end()){
          xx.insert(cc(v[i].x));
        }
        else{ //見つかった
          x_b=cc(v[i].x);
          break;
        }

        //printf("? %ld\n", cc(v[i].x));
      }
      //printf("x_b = %ld\n", x_b);

      //この線より右か左か探す
      REP(i,n){
        if(cc(v[i].x)<x_b){ //左
          px=x_b-(ry-ly)/2.0;
          break;
        }
        else if(x_b<cc(v[i].x)){ //右
          px=x_b+(ry-ly)/2.0;
          break;
        }
      }
    }
    //printf("px : %lf\npy : %lf\n",px,py);

    px/=q2;
    py/=q2;
    t=M_PI*7/4;
    double ansx=px*cos(t)-py*sin(t);
    double ansy=px*sin(t)+py*cos(t);
    //printf("  %lf  %lf\n",ansx,ansy);

    printf("%ld %ld\n", cc(ansx), cc(ansy));
  }

  return 0;
}
