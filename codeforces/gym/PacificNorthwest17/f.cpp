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


// 三角形の外心。点a,b,cは同一線上にあってはならない
Point circumcenter(Point a, Point b, Point c) {
  a = (a-c)*0.5;
  b = (b-c)*0.5;
  return c + crosspointLL(a, a*Point(1,1), b, b*Point(1,1));
}


int main(){
    // dbg(__gcd(0,0));

    int n;
    cin >>n;

    vector<Point> p(n);
    vector<int> x(n),y(n);
    rep(i,n){
        cin >>x[i] >>y[i];
        p[i] = Point(x[i],y[i]);
    }

    auto f = [&](Point q){
        vector<double> d(n);
        rep(i,n) d[i] = abs(q-p[i]);
        sort(all(d));

        int ret = n;
        rep(i,n-1){
            if(EQ(d[i], d[i+1])) --ret;
        }

        // printf(" RET = %d\n", ret);
        // rep(i,n) printf(" %.10f", d[i]);
        // printf("\n");

        return ret;
    };

    // auto parallel = [&](int i1, int i2, int j1, int j2){
    //     int vix = x[i2]-x[i1], viy = y[i2]-y[i1];
    //     int vjx = x[j2]-x[j1], vjy = y[j2]-y[j1];
    //     int g;

    //     if(vix<0){
    //         vix *= -1;
    //         viy *= -1;
    //     }
    //     g = __gcd(abs(vix), abs(viy));
    //     vix /= g;
    //     viy /= g;

    //     if(vjx<0){
    //         vjx *= -1;
    //         vjy *= -1;
    //     }
    //     g = __gcd(abs(vjx), abs(vjy));
    //     vjx /= g;
    //     vjy /= g;

    //     return vix==vjx && viy==vjy;
    // };

    int ans = n;

    // 中点
    rep(i,n)rep(j,i){
        Point q = (p[i]+p[j])*0.5;
        ans = min(ans, f(q));
    }

    // 外心
    rep(i,n)rep(j,i)rep(k,j){
        if( abs(ccw(p[i],p[j],p[k])) != 1 ) continue;
        Point q = circumcenter(p[i],p[j],p[k]);
        ans = min(ans, f(q));
    }

    // 垂直二等分線と垂直二等分線
    rep(i,n)rep(j,i)for(int k=i+1; k<n; ++k)rep(l,k){
        if(i==l || j==k || j==l) continue;

        int vix,viy;

        Point mp = (p[i]+p[j])*0.5;
        vix = x[i]-x[j];
        viy = y[i]-y[j];
        Point hp(mp.X-viy, mp.Y+vix);

        Point mq = (p[k]+p[l])*0.5;
        vix = x[k]-x[l];
        viy = y[k]-y[l];
        Point hq(mq.X-viy, mq.Y+vix);

        if( !isecLL(mp,hp,mq,hq) ) continue;
        // printf("%d %d %d %d\n",i,j,k,l);
        Point q = crosspointLL(mp,hp,mq,hq);
        ans = min(ans, f(q));
    }

    cout << ans << endl;
    return 0;
}
