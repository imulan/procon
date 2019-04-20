#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

//#define double long double

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

// 内積　dot(a,b) = |a||b|cosθ
inline double dot(Point a, Point b) {
    return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
inline double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
inline int ccw(Point a, Point b, Point c) {
    b -= a;  c -= a;
    if (cross(b,c) >  EPS) return +1;  // counter clockwise
    if (cross(b,c) < -EPS) return -1;  // clockwise
    if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と線分
inline bool isecSS(Point a1, Point a2, Point b1, Point b2) {
    return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
           ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 2直線の交点
inline Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
    assert(!EQ(d2, 0)); // 交点がない
    return a1 + d1/d2 * (a2-a1);
}

inline bool inPolygon(Point p,VP& ps){
    int n = ps.size();
    double sumAngle=0;
    rep(i,n){
        double t = arg(ps[(i+1)%n]-p)-arg(ps[i]-p);
        while(t>+PI) t-=2*PI;
        while(t<-PI) t+=2*PI;
        sumAngle += t;
    }
    return (abs(sumAngle) > 0.1);
}

// 点pの直線aへの射影点を返す
inline Point proj(Point a1, Point a2, Point p) {
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

inline double distLP(Point a1, Point a2, Point p) {
    return abs(proj(a1, a2, p) - p);
}

inline Point READ(){
    int x,y;
    scanf(" %d %d", &x, &y);
    return Point(x,y);
}

inline Point inner(Point a, Point b, Point c){
    double A = abs(b-c);
    double B = abs(c-a);
    double C = abs(a-b);

    Point p = A*a + B*b + C*c;
    p *= (1.0/(A+B+C));
    return p;
}

int main(){
    int n;
    scanf(" %d", &n);

    VP p(n);
    rep(i,n) p[i] = READ();

    VP ip(n);
    rep(i,n) ip[i] = inner(p[(i-1+n)%n],p[i],p[(i+1)%n]);

    if(n>=4){
        vector<int> ear(n);
        rep(i,n){
            Point a = p[(i-1+n)%n],  b = p[(i+1)%n];

            ear[i] = 1;

            Point mid = (a+b)*(double)0.5;
            if(!inPolygon(mid,p)) ear[i] = 0;
            if(!inPolygon(ip[i],p)) ear[i] = 0;

            if(!ear[i]) continue;

            rep(j,n){
                Point pp = p[j], qq = p[(j+1)%n];
                if(isecSS(a,b,pp,qq)){
                    Point cp = crosspointLL(a,b,pp,qq);

                    bool valid = false;
                    for(Point cc:{a,b}){
                        double dist = abs(cc-cp);
                        if(!EQ(dist,0)){
                            valid = true;
                            break;
                        }
                    }
                    if(!valid){
                        ear[i] = 0;
                        break;
                    }
                }
            }
        }

//        rep(i,n) printf("%d :: %d\n",i,ear[i]);

        rep(i,n)if(ear[i]){
            for(int j=2; j<n-1; ++j){
                int idx = (i+j)%n;
                if(ear[idx]){
                    for(int k:{i,idx}){
                        Point ans = ip[k];
                        printf("%.9f %.9f\n", ans.X, ans.Y);
                    }
                    return 0;
                }
            }
        }
        assert(false);
    }

//    triangle
    assert(n==3);

    vector<vector<Line>> l(n);
    rep(i,n){
        Point a = p[i], b = p[(i+1)%n];
        Point v = b-a;
        Point h = Point(-v.Y, v.X);
        double SZ = sqrt(h.X*h.X + h.Y*h.Y);
        h = {h.X/SZ, h.Y/SZ};
        h *= 4000;

        for(double j:{-1,1}){
            Point aa = a+(h*j), bb = b+(h*j);
            l[i].pb({aa,bb});
        }
    }

    VP tri;
    rep(i,n)rep(ii,2){
        rep(j,n)rep(jj,2)if(i<j){
            Point cp = crosspointLL(l[i][ii].fi, l[i][ii].se, l[j][jj].fi, l[j][jj].se);
            if(inPolygon(cp, p)) tri.pb(cp);
        }
    }

//    for(Point tt:tri) cout << tt <<endl;
    for(Point pp:tri)for(Point qq:tri){
        double d = abs(pp-qq);
        if( GE(d,8000) ){
            for(Point ans:{pp,qq}){
                printf("%.9f %.9f\n", ans.X, ans.Y);
            }
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}