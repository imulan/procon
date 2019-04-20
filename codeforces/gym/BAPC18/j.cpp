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
const double EPS = 1e-6; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
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
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 2円の交点
VP crosspointCC(Point a, double ar, Point b, double br) {
  VP ps;
  Point ab = b-a;
  double d = abs(ab);
  double crL = (norm(ab) + ar*ar - br*br) / (2*d);
  if (EQ(d, 0) || ar+EPS < abs(crL)) return ps;

  // 円が接する時、こことEPSの設定をうまくしないとsqrt(sub)がnanになるので注意
  double sub = ar*ar - crL*crL;
  if(EQ(sub,0)) sub = 0;

  Point abN = ab * Point(0, sqrt(sub) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
  return ps;
}

// 多角形の符号付面積
double area(const VP& ps) {
  double a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

// aからbへの回転角（中心(0,0)）[-pi,+pi]
double angle(Point a,Point b){
  double t = arg(b)-arg(a);
  while(t>+PI) t-=2*PI;
  while(t<-PI) t+=2*PI;
  return t;
}

double f(const vector<int> &s){
    Point O(0,0);
    Point A(-s[0],0);

    double l=0, r=PI;
    bool found = false;
    for(Point cp:crosspointCC(O,s[1],A,s[2]+s[3])){
        found = true;
        double ang = angle(O,cp);
        // dbg(cp);
        // dbg(ang);
        l = max(l,abs(ang));
    }
    if(!found) return 0;

    auto g = [&](double t){
        Point B = polar((double)s[1],t);
        double ret = 0;
        for(Point C:crosspointCC(B,s[2],A,s[3])){
            VP poly({O,B,C,A});
            ret = max(ret, abs(area(poly))) ;
        }
        return ret;
    };

    l += EPS;
    rep(loop,80){
        double m1 = (2*l+r)/3, m2 = (l+2*r)/3;
        // printf("%f %f\n",l,r);

        double g1 = g(m1), g2 = g(m2);
        if(EQ(g1,0) && EQ(g2,0)) r = m2;
        else{
            if(g1 > g2) r = m2;
            else l = m1;
        }
    }
    return g((l+r)/2);
}

int main(){
    vector<int> s(4);
    rep(i,4) cin >>s[i];
    sort(all(s));

    double ans = 0;
    do{
        bool largest = true;
        for(int i=1; i<3; ++i) if(s[0]<s[i]) largest = false;
        if(!largest) continue;

        ans = max(ans, f(s));
    }while(next_permutation(all(s)));

    printf("%.15f\n", ans);
    return 0;
}
