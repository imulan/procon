//http://dai1741.github.io/maximum-algo-2012/docs/geometry/
//上のものを下の資料などを元に変更
//https://github.com/not522/library/blob/master/geometry2D/geometry2D.h

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < int(n); i++)

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
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
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

/*
  交差判定　直線・線分は縮退してはならない。
  接する場合は交差するとみなす。
  縮退している = 2つのものが区別付かない状態(?)
  isec = intersect
  L = Line
  P = Point
  S = Segment
*/

// 直線と点
bool isecLP(Point a1, Point a2, Point b) {
  return abs(ccw(a1, a2, b)) != 1;
  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}


/* 距離　各直線・線分は縮退してはならない */

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

//点aと点bの距離は abs(a-b)
//#define distPP(p1,p2) abs(p1-p2)

double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}

double distLL(Point a1, Point a2, Point b1, Point b2) {
  return isecLL(a1, a2, b1, b2) ? 0 : distLP(a1, a2, b1);
}

double distLS(Point a1, Point a2, Point b1, Point b2) {
  return isecLS(a1, a2, b1, b2) ? 0 : min(distLP(a1, a2, b1), distLP(a1, a2, b2));
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  //= !ccw(a1, a2, r)
  return min(abs(a1-p), abs(a2-p));
}

double distSS(Point a1, Point a2, Point b1, Point b2) {
  if (isecSS(a1, a2, b1, b2)) return 0;
  return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
   min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}


/* 円 */

double distLC(Point a1, Point a2, Point c, double r) {
  return max(distLP(a1, a2, c) - r, 0.0);
}

double distSC(Point a1, Point a2, Point c, double r) {
  double dSqr1 = norm(c-a1), dSqr2 = norm(c-a2);
  if (dSqr1 < r*r ^ dSqr2 < r*r) return 0;  // 円が線分を包含するとき距離0ならここをORに変える
  if (dSqr1 < r*r & dSqr2 < r*r) return r - sqrt(max(dSqr1, dSqr2));
  return max(distSP(a1, a2, c) - r, 0.0);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if(!GE(r*r,norm(ft-c))) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
  ps.push_back(ft + dir);
  if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
  return ps;
}

double distCC(Point a, double ar, Point b, double br) {
  double d = abs(a-b);
  return GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;
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

/*
// 2円の交点(自作)
VP crosspointCC(Point a, double ar, Point b, double br){
  double d = abs(b-a);
  if(abs(ar-br)>d || abs(ar+br)<d) return {};
  double t = acos(double((d*d+ar*ar-br*br)/(2*d*ar)));
  Point p1 = a+polar(ar,arg(b-a)+t);
  Point p2 = a+polar(ar,arg(b-a)-t);
  if(abs(p1-p2) < EPS) return {p1};
  return {p1,p2};
}
*/

// 点pから円aへの接線の接点
VP tangentPoints(Point a, double ar, Point p) {
  VP ps;
  double sin = ar / abs(p-a);
  if (!LE(sin, 1)) return ps;  // ここでNaNも弾かれる
  double t = PI/2 - asin(min(sin, 1.0));
  ps.push_back(                 a + (p-a)*polar(sin, t));
  if (!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
  return ps;
}

// 2円の共通接線。返される各直線に含まれる頂点は円との接点となる
vector<Line> tangentLines(Point a, double ar, Point b, double br) {
  vector<Line> ls;
  double d = abs(b-a);
  rep (i,2) {
    double sin = (ar - (1-i*2)*br) / d;
    if (!LE(sin*sin, 1)) break;
    double cos = sqrt(max(1 - sin*sin, 0.0));
    rep (j,2) {
      Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;
      ls.push_back(Line(a + ar*n, b + (1-i*2)*br*n));
      if (cos < EPS) break;  // 重複する接線を無視（重複していいならこの行不要）
    }
  }
  return ls;
}

// 三角形の外心。点a,b,cは同一線上にあってはならない
Point circumcenter(Point a, Point b, Point c) {
  a = (a-c)*0.5;
  b = (b-c)*0.5;
  return c + crosspointLL(a, a*Point(1,1), b, b*Point(1,1));
}

// 点aと点bを通り、半径がrの円の中心を返す
VP circlesPointsRadius(Point a, Point b, double r) {
  VP cs;
  Point abH = (b-a)*0.5;
  double d = abs(abH);
  if (d == 0 || d > r) return cs;  // 必要なら !LE(d,r) として円1つになる側へ丸める
  double dN = sqrt(r*r - d*d);          // 必要なら max(r*r - d*d, 0) とする
  Point n = abH * Point(0,1) * (dN / d);
  cs.push_back(a + abH + n);
  if (dN > 0) cs.push_back(a + abH - n);
  return cs;
}

// 点aと点bを通り、直線lに接する円の中心
VP circlesPointsTangent(Point a, Point b, Point l1, Point l2) {
  Point n = (l2-l1) * Point(0,1);
  Point m = (b-a) * Point(0,0.5);
  double rC = dot((a+b)*0.5-l1, n);
  double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);
  double qb = -rC * dot(n,m);
  double qc = norm(n)*norm(m) - rC*rC;
  double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0

  VP cs;
  if (qd < -EPS) return cs;
  if (EQ(qa, 0)) {
    if (!EQ(qb, 0)) cs.push_back((a+b)*0.5 - m * (qc/qb/2));
    return cs;
  }
  double t = -qb/qa;
  cs.push_back(              (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0))/qa));
  if (qd > EPS) cs.push_back((a+b)*0.5 + m * (t - sqrt(max(qd, 0.0))/qa));
  return cs;
}

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const VP& ps) {
  Point c;
  double move = 0.5;
  rep(i,39) {  // 2^(-39-1) \approx 0.9e-12
    rep(t,50) {
      double max = 0;
      int k = 0;
      rep (j, ps.size()) if (max < norm(ps[j]-c)) {
        max = norm(ps[j]-c);
        k = j;
      }
      c += (ps[k]-c) * move;
    }
    move /= 2;
  }
  return c;
}


/* 多角形 */

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

// 凸判定。縮退を認めないならccwの判定部分を != 1 とする
// 反時計か分からなければreverse(ps)も試す（コピー渡し）
bool isCcwConvex(const VP& ps) {
  int n = ps.size();
  rep (i, n) if (ccw(ps[i], ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;
  return true;
}

// 凸多角形の内部判定　O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(Point p, const VP& ps) {
  int n = ps.size();
  int dir = ccw(ps[0], ps[1], p);
  rep (i, n) {
    int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
    if (!ccwc) return 2;  // 線分上に存在
    if (ccwc != dir) return 0;
  }
  return 1;
}

// 凸多角形の内部判定　O(logn)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inCcwConvex(const VP& ps, Point p) {
  int n = ps.size();
  Point g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;
  if (g == p) return 1;
  Point gp = p - g;

  int l = 0, r = n;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    Point gl = ps[l] - g;
    Point gm = ps[mid] - g;
    if (cross(gl, gm) > 0) {
      if (cross(gl, gp) >= 0 && cross(gm, gp) <= 0) r = mid;
      else l = mid;
    }
    else {
      if (cross(gl, gp) <= 0 && cross(gm, gp) >= 0) l = mid;
      else r = mid;
    }
  }
  r %= n;
  double cr = cross(ps[l] - p, ps[r] - p);
  return EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;
}

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inPolygon(const VP& ps, Point p) {
  int n = ps.size();
  bool in = false;
  rep (i, n) {
    Point a = ps[i] - p;
    Point b = ps[(i + 1) % n] - p;
    if (EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
    if (a.Y > b.Y) swap(a,b);
    if ((a.Y*b.Y < 0 || (a.Y*b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) in = !in;
  }
  return in;
}


bool inPolygon(Point p,VP& ps){
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


//ベクトル(a1->a2)で凸多角形psを切断したときの
//ベクトルの左側の凸多角形を返す
//参考 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C

// 凸多角形クリッピング
VP convexCut(const VP& ps, Point a1, Point a2) {
  int n = ps.size();
  VP ret;
  rep(i,n) {
    int ccwc = ccw(a1, a2, ps[i]);
    if (ccwc != -1) ret.push_back(ps[i]);
    int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
    if (ccwc * ccwn == -1) ret.push_back(crosspointLL(a1, a2, ps[i], ps[(i + 1) % n]));
  }
  return ret;
}

// 凸多角形の直径（最遠点対）
pair<int, int> convexDiameter(const VP& ps) {
  int n = ps.size();
  int i = min_element(ps.begin(), ps.end()) - ps.begin();
  int j = max_element(ps.begin(), ps.end()) - ps.begin();
  int maxI, maxJ;
  double maxD = 0;
  rep(_, 2*n) {
    if (maxD < norm(ps[i]-ps[j])) {
      maxD = norm(ps[i]-ps[j]);
      maxI = i;
      maxJ = j;
    }
    if (cross(ps[i]-ps[(i+1) % n], ps[(j+1) % n]-ps[j]) <= 0) j = (j+1) % n;
    else                                                      i = (i+1) % n;
  }
  return make_pair(maxI, maxJ);
}


// aからbへの回転角（中心(0,0)）[-pi,+pi]
double angle(Point a,Point b){
  double t = arg(b)-arg(a);
  while(t>+PI) t-=2*PI;
  while(t<-PI) t+=2*PI;
  return t;
}

// 多角形の符号付面積
double area(const VP& ps) {
  double a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

double areaCC(Point a, double ar, Point b, double br) {
  double d = abs(a-b);
  if (ar + br - d <= EPS) {
    return 0.0;
  } else if (d - abs(ar-br)<= EPS) {
    double r = min(ar,br);
    return r * r * PI;
  } else {
    double rc = (d*d + ar*ar - br*br) / (2*d);
    double theta = acos(rc / ar);
    double phi = acos((d - rc) / br);
    return ar*ar*theta + br*br*phi - d*ar*sin(theta);
  }
}

/* -------------最近点対の距離------------ */
bool compX(const Point a, const Point b) {
  return (a.X!=b.X ? a.X<b.X : a.Y<b.Y);
}

bool compY(const Point a, const Point b) {
  return (a.Y!=b.Y ? a.Y<b.Y : a.X<b.X);
}

double closestPair(VP& a,int l,int r) {
  if(r-l<=1) return INF;
  int m = (l+r)/2;
  double x = a[m].X;
  double d = min(closestPair(a,l,m),closestPair(a,m,r));
  inplace_merge(a.begin()+l, a.begin()+m, a.begin()+r, compY);

  VP b;
  for(int i=l;i<r;i++){
    if(abs(a[i].X - x)>=d)continue;
    for(int j=b.size()-1;j>=0;j--){
      if((a[i]-b[j]).Y>=d)break;
      d = min(d,abs(a[i]-b[j]));
    }
    b.push_back(a[i]);
  }
  return d;
}

double closestPair(VP ps){
  sort(ps.begin(),ps.end(),compX);
  return closestPair(ps,0,ps.size());
}
/* ------------------------------------- */


// 多角形の幾何学的重心
Point centroid(const VP& ps) {
  int n = ps.size();
  double aSum = 0;
  Point c;
  rep (i, n) {
    double a = cross(ps[i], ps[(i+1) % n]);
    aSum += a;
    c += (ps[i] + ps[(i+1) % n]) * a;
  }
  return 1 / aSum / 3 * c;
}

// ボロノイ領域
VP voronoiCell(Point p, const VP& ps, const VP& outer) {
  VP cl = outer;
  rep (i, ps.size()) {
    if (EQ(norm(ps[i]-p), 0)) continue;
    Point h = (p+ps[i])*0.5;
    cl = convexCut(cl, h, h + (ps[i]-h)*Point(0,1) );
  }
  return cl;
}

/* 幾何グラフ */

struct Edge {
  int from, to;
  double cost;
  Edge(int from_, int to_, double cost_) : from(from_), to(to_), cost(cost_) {}
};
struct Graph {
  int n;
  vector<vector<Edge> > edges;
  Graph(int n_) : n(n_), edges(n_) {}
  void addEdge(Edge e) {
    edges[e.from].push_back(e);
    edges[e.to].push_back(Edge(e.to, e.from, e.cost));
  }
};

// 線分アレンジメント（線分の位置関係からグラフを作成）
Graph segmentArrangement(const vector<Line>& segs, VP& ps) {
  int n = segs.size();
  rep (i, n) {
    ps.push_back(segs[i].first);
    ps.push_back(segs[i].second);
    rep (j, i) {
      if (isecSS(                 segs[i].first, segs[i].second, segs[j].first, segs[j].second))
        ps.push_back(crosspointLL(segs[i].first, segs[i].second, segs[j].first, segs[j].second));
    }
  }
  sort(ps.begin(), ps.end());
  ps.erase(unique(ps.begin(), ps.end()), ps.end());

  int m = ps.size();
  Graph gr(m);
  vector<pair<double, int> > list;
  rep (i, n) {
    list.clear();
    rep (j, m) {
      if (isecSP(segs[i].first, segs[i].second, ps[j]))
        list.push_back(make_pair(norm(segs[i].first-ps[j]), j));
    }
    sort(list.begin(), list.end());
    rep (j, list.size() - 1) {
      int a = list[j  ].second;
      int b = list[j+1].second;
      gr.addEdge(Edge(a, b, abs(ps[a]-ps[b])));
    }
  }
  return gr;
}

// 可視グラフ（点集合から見える位置へ辺を張ったグラフ）
Graph visibilityGraph(const VP& ps, const vector<VP>& objs) {
  int n = ps.size();
  Graph gr(n);
  rep (i,n) rep (j,i) {
    Point a = ps[i], b = ps[j];
    if (!EQ(norm(a-b), 0)) rep (k, objs.size()) {
      const VP& obj = objs[k];
      int inStA = inConvex(a, obj);
      int inStB = inConvex(b, obj);
      if ((inStA ^ inStB) % 2 || inStA * inStB != 1 && inConvex((a+b)*0.5, obj) == 1) goto skip;
      rep (l, obj.size()) {
        Point cur = obj[l];
        Point next = obj[(l + 1) % obj.size()];
        if (isecSS(a, b, cur, next) && !isecSP(cur, next, a) && !isecSP(cur, next, b)) goto skip;
      }
    }
    gr.addEdge( Edge(i, j, abs(a-b)) );
    skip: {}
  }
  return gr;
}


/* その他 */

// 重複する線分を併合する
vector<Line> mergeSegments(vector<Line> segs) {
  int n = segs.size();
  rep (i,n) if (segs[i].second < segs[i].first) swap(segs[i].second, segs[i].first);

  rep (i,n) rep (j,i) {
    Line &l1 = segs[i], &l2 = segs[j];
    if (EQ(cross(l1.second-l1.first, l2.second-l2.first), 0)
      && isecLP(l1.first, l1.second, l2.first)
      && ccw   (l1.first, l1.second, l2.second) != 2
      && ccw   (l2.first, l2.second, l1.second) != 2) {
      segs[j] = Line(min(l1.first, l2.first), max(l1.second, l2.second));
    segs[i--] = segs[--n];
    break;
  }
}
segs.resize(n);
return segs;
}


// 線分ABをm:nに外分する点 (m≠nでないとだめ)
Point ext_div(Point a, Point b, double m, double n){
  return (a*(-n)+b*m)/(m-n);
}

// 点cを中心に、点pをthetaだけ回転
Point rot(Point p, Point c, double theta){
  return (p-c)*polar(1.0,theta) + c;
}


// この辺にコードを載せるほどでもないが重要な定理とか図とか書いておくとよい気がします

// 余弦定理
// △ABC において、a = BC, b = CA, c = AB としたとき
// a^2 = b^2 + c^2 ? 2bc cos ∠CAB

// ヘロンの公式
// 3辺の長さがa,b,cである三角形の面積T
// T = sqrt{ s(s-a)(s-b)(s-c) }, s = (a+b+c)/2

// ピックの定理
// 多角形の頂点が全て格子点上にあり、内部に穴がないとき
// S = i + b/2 - 1 (S:多角形の面積, i: 多角形の内部にある格子点の数, b: 辺上の格子点の数)
