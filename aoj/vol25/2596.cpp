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


// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

string s;
int n;

// 0:Point, 1:Line
using V = pair<Line, int>;
Point NUL(-1,-1);

Point calc(int l, int r){
    while(s[l]=='(') ++l;
    while(s[r]==')') --r;

    int idx = l;
    while(idx<r && s[idx]!=',') ++idx;

    int x = atoi(s.substr(l,idx-l).c_str());
    int y = atoi(s.substr(idx+1,r-idx).c_str());

    return Point(x,y);
}

V AT(V l, V r){
    if(l.se > r.se) swap(l,r);

    if(l.se == 0 && r.se == 0){
        return {{l.fi.fi, r.fi.fi},1};
    }
    else if(l.se == 0 && r.se == 1){
        Point p = reflection(r.fi.fi, r.fi.se, l.fi.fi);
        return {{p, NUL}, 0};
    }
    else if(l.se == 1 && r.se == 1){
        Point p = crosspointLL(l.fi.fi, l.fi.se, r.fi.fi, r.fi.se);
        return {{p, NUL}, 0};
    }
    else assert(false);
}

// [l,r]
V f(int l, int r){
    int opct = 0;
    int d = 0;
    int pos = -1;
    for(int i=l; i<=r; ++i){
        if(s[i]=='@'){
            ++opct;
            if(d==0) pos = i;
        }
        else if(s[i]=='(') ++d;
        else if(s[i]==')') --d;
    }

    V ret;
    if(opct == 0){
        Point p = calc(l,r);
        ret = {{p,NUL},0};
    }
    else{
        if(pos != -1){
            V lh = f(l,pos-1), rh = f(pos+1,r);
            ret = AT(lh,rh);
        }
        else{
            assert(s[l]=='(' && s[r]==')');
            ret = f(l+1,r-1);
        }
    }
    return ret;
}

int main(){
    while(cin >>s,(s!="#")){
        n = s.size();
        Point ans = f(0,n-1).fi.fi;
        printf("%.10f %.10f\n", ans.X, ans.Y);
    }
    return 0;
}
