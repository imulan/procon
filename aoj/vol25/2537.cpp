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
const double EPS = 1e-9; // 許容誤差^2
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

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}


// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  //= !ccw(a1, a2, r)
  return min(abs(a1-p), abs(a2-p));
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

const int D = 10000;

int solve(int n){
    int w,h,r,vx,vy;
    scanf(" %d %d %d %d %d", &w, &h, &r, &vx, &vy);

    VP p(n);
    rep(i,n){
        int x,y;
        scanf(" %d %d", &x, &y);
        p[i] = Point(x,y);
    }

    Point now = p[0];
    double total_moved = 0;
    while(total_moved < D){
        // determine nx
        Point nx;
        if(vx==0){
            if(vy<0) nx = Point(now.X, r);
            else nx = Point(now.X, h-r);
            vy = -vy;
        }
        else if(vy==0){
            if(vx<0) nx = Point(r, now.Y);
            else nx = Point(w-r, now.Y);
            vx = - vx;
        }
        else{
            double xt,yt;
            if(vx<0) xt = (now.X-r)/abs(vx);
            else xt = (w-r-now.X)/abs(vx);

            if(vy<0) yt = (now.Y-r)/abs(vy);
            else yt = (h-r-now.Y)/abs(vy);

            if(EQ(xt,yt)){
                int xx = r;
                if(vx>0) xx = w-r;
                int yy = r;
                if(vy>0) yy = h-r;
                nx = Point(xx,yy);
                vx = -vx;
                vy = -vy;
            }
            else if(xt<yt){
                if(vx<0) nx = Point(r, now.Y+vy*xt);
                else nx = Point(w-r, now.Y+vy*xt);
                vx = -vx;
            }
            else{
                if(vy<0) nx = Point(now.X+vx*yt, r);
                else nx = Point(now.X+vx*yt, h-r);
                vy = -vy;
            }
        }

        // move
        double d = abs(now-nx);

        double cd = INF;
        int idx = -1;

        for(int i=1; i<n; ++i){
            double t = distSP(now, nx, p[i]);
            if(t<2*r){
                VP cp = crosspointLC(now,nx,p[i],2*r);
                for(Point cand:cp){
                    if( LE(total_moved + abs(now-cand),D) ){
                        if(abs(now-cand) < cd){
                            cd = abs(now-cand);
                            idx = i;
                        }
                    }
                }
            }
        }

        // answer found
        if(idx != -1) return idx+1;

        total_moved += d;
        now = nx;
    }

    return -1;
}

int main(){
    int n;
    while(scanf(" %d", &n),n) printf("%d\n", solve(n));
    return 0;
}
