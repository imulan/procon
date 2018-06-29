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

typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
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

int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 直線と点
bool isecLP(Point a1, Point a2, Point b) {
  return abs(ccw(a1, a2, b)) != 1;
  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
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

double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}


Point read_p(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int w,h,n;
    double r;
    while(cin >>w >>h >>n >>r,w){
        vector<Line> l(n);
        vector<double> t(n);
        rep(i,n){
            l[i].fi = read_p();
            l[i].se = read_p();
            cin >>t[i];
        }

        vector<Point> op;
        op.pb({r,r});
        op.pb({w-r,r});
        op.pb({w-r,h-r});
        op.pb({r,h-r});

        vector<Line> outer;
        rep(i,4) outer.pb({op[i], op[(i+1)%4]});

        vector<Line> cand;
        rep(i,n){
            Point v = l[i].se - l[i].fi;
            v = Point(v.Y, -v.X);
            Point hv = v*((t[i]+r)/abs(v));

            for(double j:{-1,1}){
                cand.pb({l[i].fi+(hv*j), l[i].se+(hv*j)});
            }
        }

        int C = cand.size();
        VP pp(op);
        rep(i,C){
            Line f = cand[i];
            rep(j,i){
                Line g = cand[j];
                if(isecLL(f.fi,f.se,g.fi,g.se)){
                    pp.pb(crosspointLL(f.fi,f.se,g.fi,g.se));
                }
            }

            for(Line g:outer){
                if(isecLL(f.fi,f.se,g.fi,g.se)){
                    pp.pb(crosspointLL(f.fi,f.se,g.fi,g.se));
                }
            }
        }

        auto IN = [&](Point p){
            return LE(r,p.X) && LE(p.X,w-r) &&LE(r,p.Y) && LE(p.Y,h-r);
        };

        auto valid = [&](Point p){
            if(!IN(p)) return false;
            rep(i,n){
                double d = distLP(l[i].fi, l[i].se, p);
                if(t[i]+r > d+EPS) return false;
            }
            return true;
        };

        bool ans = false;
        for(Point p:pp) ans |= valid(p);
        cout << (ans?"Yes":"No") << endl;
    }
    return 0;
}
