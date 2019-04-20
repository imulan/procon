#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-9;
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

VP tangentPoints(Point a, double ar, Point p){
    VP ps;
    double sin = ar / abs(p-a);
    if(!LE(sin, 1)) return ps;
    double t = PI/2 - asin(min(sin, 1.0));
    ps.pb( a + (p-a)*polar(sin,t) );
    if(!EQ(sin,1)) ps.pb( a + (p-a)*polar(sin,-t) );
    return ps;
}

Point READ(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    Point s = READ(), g = READ();

    Point bc,rc;
    double br,rr;

    bc = READ();
    cin >>br;
    rc = READ();
    cin >>rr;

    VP st = tangentPoints(rc,rr,s);
    VP gt = tangentPoints(rc,rr,g);

    auto DIST_RED = [&](Point a, Point b){
        a -= rc;
        b -= rc;

        double da = atan2(a.Y,a.X);
        double db = atan2(b.Y,b.X);

        double deg = abs(da-db);
        if(deg > PI) deg = 2*PI-deg;
        return rr*deg;
    };

    double ans = INF;
    for(Point p:st)for(Point q:gt){
        double t = abs(s-p) + DIST_RED(p,q) + abs(q-g);
        ans = min(ans, t);
    }
    printf("%.10f\n", ans);
    return 0;
}

