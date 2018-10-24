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

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

//多角形PSのi番目の辺
#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

// 凸包
// 入力1個 -> 空
// 2個以上の全て同じ点 -> 同じもの2つ
VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}


bool solve(){
    int n;
    cin >>n;
    VP p(n);
    rep(i,n){
        int x,y;
        cin >>x >>y;
        p[i] = Point(x,y);
    }

    VP ch = convexHull(p);
    int C = ch.size();

    vector<Line> cand;
    if(C%2==1){
        rep(i,C){
            Point a = ch[i];
            Point b = (ch[(i+C/2)%C] + ch[(i+1+C/2)%C])*0.5;
            cand.pb({a,b});
        }
    }
    else{
        rep(i,C){
            Point a = ch[i];
            Point b = ch[(i+C/2)%C];
            cand.pb({a,b});
        }
        rep(i,C){
            Point a = (ch[i] + ch[(i+1)%C])*0.5;
            Point b = (ch[(i+C/2)%C] + ch[(i+1+C/2)%C])*0.5;
            cand.pb({a,b});
        }
    }

    for(const auto &l:cand){
        Point a = l.fi, b = l.se;

        vector<bool> used(n);
        int on_line = 0;
        rep(i,n)if(!used[i]){
            if(abs(ccw(a,b,p[i])) != 1){
                used[i] = true;
                ++on_line;
                continue;
            }

            Point pp = reflection(a,b,p[i]);
            rep(j,n)if(i!=j && !used[j]){
                double dist = abs(pp-p[j]);
                if(EQ(dist, 0)){
                    used[i] = true;
                    used[j] = true;
                    break;
                }
            }
        }

        bool valid = true;
        rep(i,n)if(!used[i]) valid = false;

        if(n%2==1){
            if(on_line != 1) valid = false;
        }
        else{
            if( !(on_line == 0 || on_line == 2) ) valid = false;
        }

        if(valid) return true;
    }

    return false;
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
