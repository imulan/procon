#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)

using namespace std;

//点の定義
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

//円の定義
class Circle{
public:
  Point c;
  double r;
  Circle(Point c = Point(), double r=0.0): c(c), r(r) {}
};

//多角形(点の列として定義)
typedef vector<Point> Polygon;


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

//点から直線への射影
Point project(Segment s, Point p){
  Vector base = s.p2 - s.p1;
  double r = dot(p-s.p1, base) / base.norm();
  return s.p1 + base*r;
}

int main(){
  Point p1, p2;
  cin >> p1.x >> p1.y >> p2.x >> p2.y;

  Segment s;
  s.p1=p1;
  s.p2=p2;

  int q;
  scanf(" %d", &q);
  for(int i=0; i<q; ++i){
    Point p;
    cin >> p.x >> p.y;
    Point ans=project(s, p);
    printf("%.10lf %.10lf\n", ans.x, ans.y);
    //cout << ans.x  << " " << ans.y << endl;
  }

}
