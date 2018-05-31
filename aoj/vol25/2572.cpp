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
const double EPS = 1e-6; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

const double pi = acos(-1);

double areaCC(Point a, double ar, Point b, double br) {
  double d = abs(a-b);
  if (ar + br - d <= EPS) {
    return 0.0;
  } else if (d - abs(ar-br)<= EPS) {
    double r = min(ar,br);
    return r * r * pi;
  } else {
    double rc = (d*d + ar*ar - br*br) / (2*d);
    double theta = acos(rc / ar);
    double phi = acos((d - rc) / br);
    return ar*ar*theta + br*br*phi - d*ar*sin(theta);
  }
}

double find_R(double area){
    return sqrt(area/pi);
}

int uw,uh,A,B,AandB;
void solve(){
    double ra = find_R(A), rb = find_R(B);

    bool flg = false;
    if(A<B){
        flg = true;
        swap(ra,rb);
        swap(A,B);
    }

    if(2*ra > min(uw,uh)){
        printf("impossible\n");
        return;
    }

    Point p_a(ra, ra), p_b(uw-rb, uh-rb);
    double dx = p_b.X - p_a.X, dy = p_b.Y - p_a.Y;
    double D = sqrt(dx*dx+dy*dy);
    dx /= D;
    dy /= D;

    auto calc_area = [&](Point q){
        return areaCC(p_a, ra, q, rb);
    };

    double l=0, r=D;
    rep(loop,80){
        double m=(l+r)/2;
        Point cand(p_a.X+dx*m, p_a.Y+dy*m);

        // printf(" m %f : area %.10f\n", m, calc_area(cand));
        if(calc_area(cand) <= AandB) r=m;
        else l=m;
    }

    p_b = Point(p_a.X+dx*l, p_a.Y+dy*l);
    if( EQ(calc_area(p_b), AandB) ){
        // dbg(abs(p_a-p_b));
        if(flg){
            swap(p_a, p_b);
            swap(ra,rb);
        }
        printf("%.10f %.10f %.10f %.10f %.10f %.10f\n", p_a.X, p_a.Y, ra, p_b.X, p_b.Y, rb);
    }
    else printf("impossible\n");
}

int main(){
    while(cin >>uw >>uh >>A >>B >>AandB,uw) solve();
    return 0;
}
