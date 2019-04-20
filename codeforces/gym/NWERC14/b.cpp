#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int LOOP = 70;

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

Point scan_p(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

const int N = 1010;

double dist(Point p, Point q){
    return abs(p-q);
}

int main(){
    double v_walk, v_bike;
    cin >>v_walk >>v_bike;

    double lx,ly,rx,ry;
    cin >>lx >>ly >>rx >>ry;

    Point start,goal;
    start = scan_p();
    goal = scan_p();

    int n;
    cin >>n;

    VP p(n);
    rep(i,n) p[i] = scan_p();

    double ans = dist(start,goal)/v_walk;

    // 2点に直接行くパターン
    rep(i,n)rep(j,n){
        double tmp = dist(start,p[i])/v_walk + dist(p[i],p[j])/v_bike + dist(p[j],goal)/v_walk;
        ans = min(ans, tmp);
    }

    // start -> 周上 -> p[i] -> goal
    // goal -> 周上 -> p[i] -> start
    rep(aaaaa,2){
        rep(i,n){
            for(double yy:vector<double>({ly,ry})){
                double l = min(start.X, p[i].X), r = max(start.X, p[i].X);
                rep(loop,LOOP){
                    double midl = (2*l+r)/3, midr = (l+2*r)/3;
                    double distl = dist(start,Point(midl,yy))/v_walk + dist(Point(midl,yy),p[i])/v_bike;
                    double distr = dist(start,Point(midr,yy))/v_walk + dist(Point(midr,yy),p[i])/v_bike;

                    if(distl < distr) r = midr;
                    else l = midl;
                }

                ans = min(ans, dist(start,Point(l,yy))/v_walk + dist(Point(l,yy),p[i])/v_bike + dist(p[i],goal)/v_walk);
            }

            for(double xx:vector<double>({lx,rx})){
                double l = min(start.Y, p[i].Y), r = max(start.Y, p[i].Y);
                rep(loop,LOOP){
                    double midl = (2*l+r)/3, midr = (l+2*r)/3;
                    double distl = dist(start,Point(xx,midl))/v_walk + dist(Point(xx,midl),p[i])/v_bike;
                    double distr = dist(start,Point(xx,midr))/v_walk + dist(Point(xx,midr),p[i])/v_bike;

                    if(distl < distr) r = midr;
                    else l = midl;
                }

                ans = min(ans, dist(start,Point(xx,l))/v_walk + dist(Point(xx,l),p[i])/v_bike + dist(p[i],goal)/v_walk);
            }
        }
        swap(start,goal);
    }

    // start -> 周上 -> 周上 -> goal
    for(double yy:vector<double>({ly,ry}))for(double yyy:vector<double>({ly,ry})){
        auto D = [&](Point ppp){
            double ll = lx, rr = rx;
            rep(loop2,LOOP){
                double midll = (2*ll+rr)/3, midrr = (ll+2*rr)/3;

                double distll = dist(start,ppp)/v_walk + dist(ppp,Point(midll,yyy))/v_bike + dist(Point(midll,yyy),goal)/v_walk;
                double distrr = dist(start,ppp)/v_walk + dist(ppp,Point(midrr,yyy))/v_bike + dist(Point(midrr,yyy),goal)/v_walk;

                if(distll<distrr) rr = midrr;
                else ll = midll;
            }
            return dist(start,ppp)/v_walk + dist(ppp,Point(ll,yyy))/v_bike + dist(Point(ll,yyy),goal)/v_walk;
        };

        double l = lx, r = rx;
        rep(loop,LOOP){
            double midl = (2*l+r)/3, midr = (l+2*r)/3;
            Point pl(midl, yy), pr(midr, yy);

            if(D(pl)<D(pr)) r = midr;
            else l = midl;
        }

        ans = min(ans, D(Point(l, yy)));
    }

    for(double xx:vector<double>({lx,rx}))for(double yyy:vector<double>({ly,ry})){
        auto D = [&](Point ppp){
            double ll = lx, rr = rx;
            rep(loop2,LOOP){
                double midll = (2*ll+rr)/3, midrr = (ll+2*rr)/3;

                double distll = dist(start,ppp)/v_walk + dist(ppp,Point(midll,yyy))/v_bike + dist(Point(midll,yyy),goal)/v_walk;
                double distrr = dist(start,ppp)/v_walk + dist(ppp,Point(midrr,yyy))/v_bike + dist(Point(midrr,yyy),goal)/v_walk;

                if(distll<distrr) rr = midrr;
                else ll = midll;
            }
            return dist(start,ppp)/v_walk + dist(ppp,Point(ll,yyy))/v_bike + dist(Point(ll,yyy),goal)/v_walk;
        };

        double l = ly, r = ry;
        rep(loop,LOOP){
            double midl = (2*l+r)/3, midr = (l+2*r)/3;
            Point pl(xx, midl), pr(xx, midr);

            if(D(pl)<D(pr)) r = midr;
            else l = midl;
        }

        ans = min(ans, D(Point(xx, l)));
    }

    for(double yy:vector<double>({ly,ry}))for(double xxx:vector<double>({lx,rx})){
        auto D = [&](Point ppp){
            double ll = ly, rr = ry;
            rep(loop2,LOOP){
                double midll = (2*ll+rr)/3, midrr = (ll+2*rr)/3;

                double distll = dist(start,ppp)/v_walk + dist(ppp,Point(xxx,midll))/v_bike + dist(Point(xxx,midll),goal)/v_walk;
                double distrr = dist(start,ppp)/v_walk + dist(ppp,Point(xxx,midrr))/v_bike + dist(Point(xxx,midrr),goal)/v_walk;

                if(distll<distrr) rr = midrr;
                else ll = midll;
            }
            return dist(start,ppp)/v_walk + dist(ppp,Point(xxx,ll))/v_bike + dist(Point(xxx,ll),goal)/v_walk;
        };

        double l = lx, r = rx;
        rep(loop,LOOP){
            double midl = (2*l+r)/3, midr = (l+2*r)/3;
            Point pl(midl, yy), pr(midr, yy);

            if(D(pl)<D(pr)) r = midr;
            else l = midl;
        }

        ans = min(ans, D(Point(l, yy)));
    }

    for(double xx:vector<double>({lx,rx}))for(double xxx:vector<double>({lx,rx})){
        auto D = [&](Point ppp){
            double ll = ly, rr = ry;
            rep(loop2,LOOP){
                double midll = (2*ll+rr)/3, midrr = (ll+2*rr)/3;

                double distll = dist(start,ppp)/v_walk + dist(ppp,Point(xxx,midll))/v_bike + dist(Point(xxx,midll),goal)/v_walk;
                double distrr = dist(start,ppp)/v_walk + dist(ppp,Point(xxx,midrr))/v_bike + dist(Point(xxx,midrr),goal)/v_walk;

                if(distll<distrr) rr = midrr;
                else ll = midll;
            }
            return dist(start,ppp)/v_walk + dist(ppp,Point(xxx,ll))/v_bike + dist(Point(xxx,ll),goal)/v_walk;
        };

        double l = ly, r = ry;
        rep(loop,LOOP){
            double midl = (2*l+r)/3, midr = (l+2*r)/3;
            Point pl(xx, midl), pr(xx, midr);

            if(D(pl)<D(pr)) r = midr;
            else l = midl;
        }

        ans = min(ans, D(Point(xx, l)));
    }

    printf("%.10f\n", ans);
    return 0;
}
