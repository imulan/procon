#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)

using namespace std;

class Point{
  public:
  double x, y;

  Point(double x=0, double y=0): x(x), y(y) {}

  Point operator + (Point p) { return Point(x+p.x, y+p.y); }
  Point operator - (Point p) { return Point(x-p.x, y-p.y); }
  Point operator * (double a) { return Point(a*x, a*y); }
  Point operator / (double a) { return Point(x/a, y/a); }

  double abs() {return sqrt(norm()); }
  double norm() { return x*x+y*y; }

  bool operator < (const Point &p) const{
    return x!=p.x ? x<p.x : y<p.y;
  }

  bool operator == (const Point &p) const{
    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
  }

};

//(図形的な)ベクトルも点と同様に定義できる
typedef Point Vector;

//線分の定義
typedef struct Segment{
  Point p1, p2;
}Segment;

//直線も同様に定義
typedef Segment Line;


//ベクトルの内積
double dot(Vector a, Vector b){
  return a.x*b.x+a.y*b.y;
}

//ベクトルの外積
double cross(Vector a, Vector b){
  return a.x*b.y-a.y*b.x;
}

//直交判定(ベクトルの内積が0なら直交)
bool isOrthogonal(Vector a, Vector b){
  return equals(dot(a,b), 0.0);
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
  return isOrthogonal(a1- a2, b1-b2);
}
bool isOrthogonal(Segment s1, Segment s2){
  return equals(dot(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}

//平行判定(ベクトルの外積の大きさが0なら平行)
bool isParallel(Vector a, Vector b){
  return equals(cross(a,b), 0.0);
}
bool isParallel(Point a1, Point a2, Point b1, Point b2){
  return isParallel(a1- a2, b1-b2);
}
bool isParallel(Segment s1, Segment s2){
  return equals(cross(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}



int main(){
  int q;
  scanf(" %d", &q);
  for(int i=0; i<q; ++i){
    Segment a,b;
    scanf(" %lf %lf %lf %lf %lf %lf %lf %lf", &a.p1.x, &a.p1.y, &a.p2.x, &a.p2.y, &b.p1.x, &b.p1.y, &b.p2.x, &b.p2.y );

    if(isParallel(a,b)) printf("2\n");
    else if(isOrthogonal(a,b)) printf("1\n");
    else printf("0\n");
  }
}
