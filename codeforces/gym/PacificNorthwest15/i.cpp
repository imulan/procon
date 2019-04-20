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

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};


/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-7; // 許容誤差^2
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


Point READ(){
    double x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n;
    cin >>n;

    VP c(n);
    rep(i,n) c[i] = READ();

    VP cand;
    UF uf(n);
    rep(i,n)rep(j,i){
        double d = abs(c[i]-c[j]);
        if(LE(d,2)) uf.unite(i,j);

        for(Point cp:crosspointCC(c[i],2,c[j],2)) cand.pb(cp);
    }

    int ans = 0;
    rep(i,n) ans = max(ans, uf.size(i)+1);

    for(Point p:cand){
        set<int> cc;
        rep(i,n){
            double d = abs(p-c[i]);
            if(LE(d,2)) cc.insert(uf.root(i));
        }

        int t = 1;
        for(int i:cc) t += uf.size(i);
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
