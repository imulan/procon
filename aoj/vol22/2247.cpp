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

const double PI = acos(-1);

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

int main(){
    int n,D;
    while(cin >>n >>D,n){
        vector<int> Ls(n),Rs(n),t(n);
        rep(i,n) cin >>Ls[i] >>Rs[i] >>t[i];

        Point l(-D,0),r(D,0);
        double dir = PI/2;

        rep(i,n){
            if(Ls[i]==Rs[i]){
                double d = 2*PI*abs(Ls[i])/360.0*t[i];
                double x = d*cos(dir), y = d*sin(dir);
                if(Ls[i]<0){
                    x = -x;
                    y = -y;
                }

                l += Point(x,y);
                r += Point(x,y);
            }
            else{
                Point c;
                int rot = 1;
                if(Ls[i]==0){
                    c = l;
                    if(Rs[i]<0) rot = -1;
                }
                else if(Rs[i]==0){
                    c = r;
                    if(Ls[i]>0) rot =- 1;
                }
                else{
                    double aL = abs(Ls[i]), aR = abs(Rs[i]);
                    if(Ls[i]*Rs[i]>0){
                        // 外分点
                        double q = aL-aR;
                        c = (l*(-aR) + r*aL)/q;
                        if(Ls[i]>Rs[i]) rot = -1;
                    }
                    else{
                        // 内分点
                        double q = aL+aR;
                        c = (l*aR + r*aL)/q;
                        if(Ls[i]>0) rot = -1;
                    }
                }

                double theta;
                if(abs(c-l)>abs(c-r)){
                    double d = 2*PI*abs(Ls[i])/360.0*t[i];
                    theta = d/abs(c-l);
                }
                else{
                    double d = 2*PI*abs(Rs[i])/360.0*t[i];
                    theta = d/abs(c-r);
                }
                theta = rot*theta;

                l = (l-c)*polar(1.0,theta) + c;
                r = (r-c)*polar(1.0,theta) + c;
                dir += theta;
            }

            assert(EQ(abs(l-r),2*D));
        }

        Point ans = (l+r)*0.5;
        printf("%.10f\n%.10f\n", ans.X, ans.Y);
    }
    return 0;
}
