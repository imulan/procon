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

struct edge{
    int to;
    double cost;
};

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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
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

VP read_polygon(){
    int n;
    scanf(" %d", &n);
    VP p(n);
    rep(i,n){
        int x,y;
        scanf(" %d %d", &x, &y);
        p[i] = Point(x,y);
    }
    return p;
}

vector<edge> G[100],oG[100];

int main(){
    VP inner = read_polygon();
    VP outer = read_polygon();
    int n = inner.size(), m = outer.size();

    VP inner_ch = convexHull(inner);
    int C = inner_ch.size();

    // 凸包の各頂点の、元のinnerでの頂点番号
    vector<int> v2id(C);
    rep(i,C){
        rep(j,n){
            if( LE(abs(inner_ch[i]-inner[j]),0) ){
                v2id[i] = j;
                break;
            }
        }
    }
    // dbg(v2id);
    // rep(i,C) dbg(inner[v2id[i]]);

    // ゴールライン
    Point gp = inner_ch[0], gq = Point(gp.X-0.5, -5050);

    // pとqを結んで良いか？
    auto check = [&](Point p, Point q){
        // innerと交差が無いか
        rep(i,n){
            Point a = inner[i], b = inner[(i+1)%n];
            // 端点に一致したら無視
            if(LE(abs(p-a),0) || LE(abs(p-b),0) || LE(abs(q-a),0) || LE(abs(q-b),0)) continue;

            if(isecSS(p,q,a,b)) return false;
        }

        // outerと交差が無いか
        rep(i,m){
            Point a = outer[i], b = outer[(i+1)%m];
            // 端点に一致したら無視
            if(LE(abs(p-a),0) || LE(abs(p-b),0) || LE(abs(q-a),0) || LE(abs(q-b),0)) continue;

            if(isecSS(p,q,a,b)) return false;
        }

        // innerの中に入ってしまっていないか
        // 中点を代表にしてチェック
        if(inPolygon(inner, (p+q)*0.5) == 1) return false;

        // outerの外に出てしまっていないか
        // 中点を代表にしてチェック
        if(inPolygon(outer, (p+q)*0.5) == 0) return false;

        if( !(LE(abs(gp-p),0) || LE(abs(gp-q),0)) ){
            // ゴールラインをまたがないようにする
            if(isecSS(gp,gq,p,q)) return false;
        }

        return true;
    };

    int V = n+m;
    double ans = 0;
    // 凸包上の点は通過する必要があるのでチェックポイントとし、
    // i -> i+1に移動するための最短経路を求める

    // outer と outer を結ぶ
    rep(j,m){
        for(int k=1; k<m/2; ++k){
            Point p = outer[j], q = outer[(j+k)%m];
            if(check(p,q)){
                // printf(" j,k %d %d\n",n+j,n+(j+k)%m);
                oG[n+j].pb({n+(j+k)%m, abs(p-q)});
            }
        }
    }

    rep(i,C){
        rep(j,V) G[j].clear();

        int u = v2id[(i+1)%C], v = v2id[i];
        int w = u-v;
        if(w<0) w += n;

        // printf("--------------- %d  (%d -> %d)\n", i,v,u);

        rep(j,w+1){
            Point p = inner[(v+j)%n];

            // inner と inner を結ぶ
            for(int k=j+1; k<w+1; ++k){
                Point q = inner[(v+k)%n];
                if(check(p,q)){
                    // printf(" EDGE: %d %d\n", (v+j)%n, (v+k)%n);
                    if(i==0 && k==0) continue;
                    if(i==C-1 && (v+j)%n==u) continue;

                    G[(v+j)%n].pb({(v+k)%n, abs(p-q)});
                }
            }

            // inner と outerを結ぶ
            rep(k,m){
                Point q = outer[k];
                if(check(p,q)){
                    // printf(" IO EDGE: %d %d\n", (v+j)%n, k);
                    if( !(i==0 && (v+j)%n==v)) G[n+k].pb({(v+j)%n, abs(p-q)});

                    if( !(i==C-1 && (v+j)%n==u) ) G[(v+j)%n].pb({n+k, abs(p-q)});
                }
            }
        }

        // vector<int> par(V,-1);
        vector<double> d(V,INF);
        d[v] = 0;
        using P = pair<double,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,v});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int pos = now.se;
            if(pos==u) break;
            if(now.fi>d[pos]) continue;
            for(const auto &e:G[pos]){
                if(d[e.to] > d[pos]+e.cost+EPS){
                    // par[e.to] = now;
                    d[e.to] = d[pos]+e.cost;
                    pq.push({d[e.to],e.to});
                }
            }
            for(const auto &e:oG[pos]){
                if(d[e.to] > d[pos]+e.cost+EPS){
                    // par[e.to] = now;
                    d[e.to] = d[pos]+e.cost;
                    pq.push({d[e.to],e.to});
                }
            }
        }

        // int now = u;
        // while(par[now]!=-1){
        //     printf(" %d -> %d\n", now, par[now]);
        //     now = par[now];
        // }

        assert(d[u]<INF);
        ans += d[u];
        // dbg(d[u]);
    }

    printf("%.10f\n", ans);
    return 0;
}
