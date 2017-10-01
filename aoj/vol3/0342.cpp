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
const double EPS = 1e-8; // 許容誤差^2
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
    bool unite(int XX,int YY){
        XX=root(XX); YY=root(YY);
        if(XX==YY) return false;
        if(size(XX) < size(YY)) swap(XX,YY);
        d[XX]+=d[YY];
        d[YY]=XX;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int XX,int YY){ return root(XX)==root(YY); }
};

using pi = pair<int,int>;
using edge = pair<double,pi>;

int main()
{
    int V,R;
    cin >>V >>R;

    VP p(V);
    rep(i,V)
    {
        int x,y;
        cin >>x >>y;
        p[i] = Point(x,y);
    }

    vector<edge> e(R);
    rep(i,R)
    {
        int s,t;
        cin >>s >>t;
        --s;
        --t;
        e[i] = {abs(p[s]-p[t]),{s,t}};
    }
    sort(all(e));

    VP cv = convexHull(p);
    int CV = cv.size();

    double ans = 0;
    UF uf(V);
    rep(i,CV)
    {
        int pp = 0;
        while(!EQ(p[pp],cv[i])) ++pp;
        int qq = 0;
        while(!EQ(p[qq],cv[(i+1)%CV])) ++qq;

        ans += abs(p[pp]-p[qq]);
        uf.unite(pp,qq);
    }

    rep(i,R)
    {
        int s = e[i].se.fi, t = e[i].se.se;
        if(!uf.same(s,t))
        {
            uf.unite(s,t);
            ans += e[i].fi;
        }
    }

    printf("%.10f\n", ans);
    return 0;
}
