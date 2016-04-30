#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
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

double norm(Vector a){
  return a.x*a.x + a.y*a.y;
}

double abs(Vector a){
  return sqrt(norm(a));
}

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
  double r = dot(p-s.p1, base) / norm(base);
  return s.p1 + base*r;
}

//反射(直線に対して線対称の位置にある点)
Point reflect(Segment s, Point p){
  return p+(project(s,p)-p)*2.0;
}

//Counter-Clockwise(3点の位置関係)
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){ //p0, p1, p2の順に見た時の位置関係
  Vector a = p1-p0;
  Vector b = p2-p0;
  if( cross(a,b) > EPS) return COUNTER_CLOCKWISE; //正なら反時計回り(右ねじ)
  if( cross(a,b) < -EPS) return CLOCKWISE;
  if( dot(a,b) < -EPS) return ONLINE_BACK; //外積が0で内積が負，つまり180°に開いている
  if( norm(a) < norm(b) ) return ONLINE_FRONT; //p0から見てp1よりp2が遠い

  return ON_SEGMENT;
}

//線分の交差判定
bool intersect(Segment s1, Segment s2){
  return true;
}

//点aと点bの距離
double getDistance(Point a, Point b){
  return abs(a-b);
}

//点と直線の距離
double getDistanceLP(Line l, Point p){
  return abs(cross(l.p2-l.p1, p-l.p1)) / abs(l.p2-l.p1);
}

//点と線分の距離
double getDistanceSP(Segment s, Point p){
  if( dot(s.p2-s.p1, p-s.p1)<0.0 ) return abs(p-s.p1);
  if( dot(s.p1-s.p2, p-s.p2)<0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

//線分と線分の距離
double getDistance(Segment s1, Segment s2){
  if( intersect(s1,s2) ) return 0.0;
  return min( min(getDistanceSP(s1,s2.p1), getDistanceSP(s1,s2.p2)), min(getDistanceSP(s2,s1.p1), getDistanceSP(s2,s1.p2)) );
}

int main(){
  Point p0, p1;
  cin >> p0.x >> p0.y >> p1.x >> p1.y;

  int q;
  cin >> q;
  for(int i=0; i<q; ++i){
    Point p2;
    cin >> p2.x >> p2.y;
    int ans=ccw(p0,p1,p2);

    string s;
    if(ans==-2) s="ONLINE_FRONT";
    else if(ans==-1) s="CLOCKWISE";
    else if(ans==0) s="ON_SEGMENT";
    else if(ans==1) s="COUNTER_CLOCKWISE";
    else if(ans==2) s="ONLINE_BACK";

    cout << s <<endl;
  }
}
