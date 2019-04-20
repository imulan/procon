#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back
#define fi first
#define se second

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
double EPS = 1e-9;

#define X real()
#define Y imag()

#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) ((n)+EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c){
    b-=a; c-=a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

bool isecLS(Point a1, Point a2, Point b1, Point b2){
    return cross(a2-a1, b1-a1)*cross(a2-a1,b2-a1) < EPS;
}


Point crosspointLL(Point a1, Point a2, Point b1, Point b2){
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if(EQ(d1,0) && EQ(d2,0)) return a1;
    assert(!EQ(d2,0));
    return a1 + d1/d2 * (a2-a1);
}

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

VP convexHull(VP ps){
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    VP ch(2*n);
    for(int i=0; i<n; ch[k++]=ps[i++])
        while(k>=2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for(int i=n-2, t=k+1; i>=0; ch[k++]=ps[i--])
        while(k>=t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

double area(const VP &ps){
    double a = 0;
    rep(i,ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
    return a/2;
}


Point read_p(){
    double x,y;
    cin >>x >>y;
    return Point(x,y);
}

using P = pair<double,Point>;

double get_deg(Point c){
    double rad = atan2(c.Y, c.X);
    if(rad<-EPS) rad = 2*PI + rad;
    return rad;
}

int main(){
    vector<P> b(4);
    rep(i,4){
        Point c = read_p();
        b[i] = {get_deg(c),c};
    }

    vector<P> r;
    rep(i,4){
        if(EQ(b[i].se.X,0.5) || EQ(b[i].se.X,-0.5) || EQ(b[i].se.Y,0.5) || EQ(b[i].se.Y,-0.5)) r.pb(b[i]);
    }

    rep(i,4){
        Point b1 = b[i].se, b2 = b[(i+1)%4].se;

        for(double cc:vector<double>({-0.5, 0.5})){
            if(!EQ(b1.X,cc) && !EQ(b2.X,cc)){
                Point x1(cc,-100), x2(cc,100);
                if(isecLS(x1,x2,b1,b2)){
                    Point cp = crosspointLL(x1,x2,b1,b2);
                    r.push_back({get_deg(cp), cp});
                }
            }

            if(!EQ(b1.Y,cc) && !EQ(b2.Y,cc)){
                Point y1(-100,cc), y2(100,cc);
                if(isecLS(y1,y2,b1,b2)){
                    Point cp = crosspointLL(y1,y2,b1,b2);
                    r.push_back({get_deg(cp), cp});
                }
            }
        }
    }
    sort(r.begin(), r.end());

    int R = r.size();

    // printf(" R %d\n", R);
    // rep(i,R){
    //     printf(" %f %f \n", r[i].se.X, r[i].se.Y);
    // }

    assert(R==8);

    Point corner[4];
    corner[0] = Point(0.5, 0.5);
    corner[1] = Point(-0.5, 0.5);
    corner[2] = Point(-0.5, -0.5);
    corner[3] = Point(0.5, -0.5);

    int dice[8] = {9,6,10,4,5,1,4,3};

    double ans = 0;
    rep(i,R){
        // printf(" CALC i %d\n",i);
        VP poly;
        poly.pb(r[i].se);
        poly.pb(r[(i+1)%R].se);
        poly.pb(corner[i/2]);
        if((i+1)%R/2 != i/2) poly.pb(corner[(i+1)%R/2]);

        double Ldeg = r[i].fi, Rdeg = r[(i+1)%R].fi;
        if(Ldeg > Rdeg) Rdeg += 2*PI;
        // printf(" %f %f\n", Ldeg, Rdeg);

        rep(j,4){
            for(int mul=-1; mul<=1; ++mul){
                if(LE(Ldeg+mul*2*PI, b[j].fi) && LE(b[j].fi, Rdeg+mul*2*PI)) poly.pb(b[j].se);
            }
        }

        // printf("SZ %d\n", poly.size());
        double AA = abs(area(convexHull(poly)));

        ans += AA*(dice[i] + 4*(dice[i]+5));
    }
    ans += 4*5;

    double V = 5*5*5 - 1;
    printf("%.10f\n", ans/V);
    return 0;
}
