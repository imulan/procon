#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-7; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

using Vec = Point;

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}


// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if(!GE(r*r,norm(ft-c))) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
  ps.push_back(ft + dir);
  if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
  return ps;
}

// 多角形の符号付面積
double area(const VP& ps) {
  double a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

// 多角形の幾何学的重心
Point centroid(const VP& ps) {
  int n = ps.size();
  double aSum = 0;
  Point c;
  rep (i, n) {
    double a = cross(ps[i], ps[(i+1) % n]);
    aSum += a;
    c += (ps[i] + ps[(i+1) % n]) * a;
  }
  return 1 / aSum / 3 * c;
}

// aからbへの回転角（中心(0,0)）[-pi,+pi]
double angle(Point a,Point b){
  double t = arg(b)-arg(a);
  while(t>+PI) t-=2*PI;
  while(t<-PI) t+=2*PI;
  return t;
}

bool on_arc(Point c, Point a, Point b, Point p){
    b -= c;
    a -= c;
    p -= c;
    c -= c;

    double ta = atan2(a.Y,a.X), tb = atan2(b.Y,b.X);
    while(tb - ta < 0){
        tb += 2*PI;
    }
    if(tb - ta > PI){
        swap(ta,tb);
    }
    while(tb - ta < 0){
        tb += 2*PI;
    }

    for(int i=-2; i<=2; ++i){
        double tmp = atan2(p.Y,p.X) + i*2*PI;
        if(ta-EPS<tmp && tmp<tb+EPS) return true;
    }
    return false;
}

double cb(double x){
    return x*x*x;
}

Point READ(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    string s;
    while(cin >>s, (s=="start")){
        Point start = READ();

        VP poly;
        vector<int> arc;

        poly.pb(start);
        while(cin >>s){
            if(s == "close"){
                arc.pb(0);
                break;
            }

            poly.pb(READ());

            int rr = 0;
            if(s == "arc") cin >>rr;
            arc.pb(rr);
        }

        int n = poly.size();

        // calc center of mass
        Point pg = centroid(poly);
        double poly_area = area(poly);

        Point g = poly_area*pg;
        double mm = poly_area;

        VP arc_center(n);
        rep(i,n)if(arc[i]!=0){
            Point a = poly[i], b = poly[(i+1)%n];
            Point mid = (a+b)*0.5;

            Vec v = b-a;
            Vec h = {-v.Y, v.X};
            double hsz = abs(h);
            h = {h.X/hsz, h.Y/hsz};

            double chord = abs(b-a);
            double theta = asin(chord/2/abs(arc[i]));
            double len = abs(arc[i])*cos(theta);

            // determine the center of the arc
            Point c1 = mid + len*h;
            Point c2 = mid - len*h;
            if(arc[i]<0){
                if( angle(a-c1, b-c1) > EPS) arc_center[i] = c1;
                else arc_center[i] = c2;
            }
            else{
                if( angle(a-c1, b-c1) < -EPS) arc_center[i] = c1;
                else arc_center[i] = c2;
            }

            VP cross_points = crosspointLC(arc_center[i], mid, arc_center[i], abs(arc[i]));
            for(Point tmp:cross_points){
                if(on_arc(arc_center[i], a, b, tmp)){
                    double A = arc[i]*arc[i]*(2*theta - sin(2*theta))/2;
                    double y = 2*cb(abs(arc[i]))*cb(sin(theta))/3/A;
                    Point tgp = arc_center[i] + (mid-arc_center[i])*(y/abs(mid-arc_center[i]));

                    double mul = 1;
                    if(arc[i]>0) mul = -1;
                    g += tgp*(A*mul);
                    mm += A*mul;
                    break;
                }
            }
        }
        g *= (1.0/mm);

        // is center inside?
        int yct = 0;
        for(int yy=-200; yy<=200; ++yy){

            Point GP(200, yy);
            // dbg(GP);
            VP cps;
            rep(i,n){
                Point a = poly[i], b = poly[(i+1)%n];
                if(arc[i] == 0){
                    // dbg(a);
                    // dbg(b);
                    if(isecLS(g,GP,a,b)){
                        Point cp = crosspointLL(g,GP,a,b);
                        // dbg(cp);
                        if(cp.X - g.X > 0) cps.pb(cp);
                    }
                }
                else{
                    for(Point cp:crosspointLC(g,GP,arc_center[i],abs(arc[i]))){
                        if(on_arc(arc_center[i],a,b,cp)){
                            if(cp.X - g.X > 0) cps.pb(cp);
                        }
                    }
                }
            }

            VP uniq_cps;
            for(Point p:cps){
                bool ok = true;
                for(Point q:uniq_cps){
                    if(abs(p-q)<EPS) ok = false;
                }
                if(ok) uniq_cps.pb(p);
            }
            // dbg(uniq_cps);
            if(uniq_cps.size()%2==0) ++yct;
            else --yct;
        }
        // dbg(yct);

        char inside = '+';
        if(yct>0) inside = '-';

        printf("%.10f %.10f %c\n", g.X, g.Y, inside);
    }
    return 0;
}
