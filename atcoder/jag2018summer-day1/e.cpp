#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef complex<double> Point;
typedef vector<Point> VP;

const double PI = acos(-1);
const double EPS = 1e-9;

#define X real()
#define Y imag()

#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

inline double sq(double x){
    return x*x;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

double area(const VP& ps){
    double a = 0;
    rep(i,ps.size()) a+=cross(ps[i],ps[(i+1)%ps.size()]);
    return a/2;
}

double solve(){
    double c;
    int n;
    cin >>c >>n;

    vector<double> l(n);
    rep(i,n) cin >>l[i];

    double cr = c/2/PI;

    auto check = [&](double rr){
        rep(i,n){
            if(LE(2*rr, l[i])) return false;
        }

        rep(i,n){
            double sum = 0;
            rep(j,n-1){
                int idx = (i+j)%n;
                double theta = acos( (2*sq(rr)-sq(l[idx]))/(2*sq(rr)) );
                sum += theta;
            }
            Point p(rr,0),q(rr*cos(sum),rr*sin(sum));
            double dist = abs(p-q);
            if( LE(dist, l[(i+n-1)%n])) return false;
        }
        return true;
    };

    double L=0,R=cr;
    rep(loop,100){
        double mid = (L+R)/2;
        if(check(mid)) R=mid;
        else L=mid;
    }
    // printf("cr %f R %f\n", cr,R);
    R = L;
    vector<Point> pts;
    rep(i,n){
        double sum = 0;
        rep(j,n-1){
            int idx = (i+j)%n;
            double theta = acos( (2*sq(R)-sq(l[idx]))/(2*sq(R)) );
            sum += theta;
        }
        Point p(R,0),q(R*cos(sum),R*sin(sum));
        double dist = abs(p-q);

        if( EQ(dist, l[(i+n-1)%n])){
            double alpha = 0;
            pts.pb(Point(R,0));
            rep(k,n-1){
                int idx = (i+k)%n;

                double tt = acos( (2*sq(R)-sq(l[idx]))/(2*sq(R)) );
                alpha += tt;
                pts.pb(Point(R*cos(alpha), R*sin(alpha)));
            }
            break;
        }
    }

    // assert(pts.size() == n);
    // rep(i,n){
    //     printf("%f %f\n", pts[i].X, pts[i].Y);
    // }

    double ret = cr*cr*PI;
    ret -= abs(area(pts));
    return ret;
}

int main(){
    int T;
    cin >>T;
    while(T--) printf("%.10f\n", solve());
    return 0;
}
