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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inPolygon(Point p, const VP& ps) {
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

Point READ(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n,m;
    cin >>n >>m;

    vector<VP> room(n);
    vector<int> sz(n);
    VP b(n);
    rep(i,n){
        cin >>sz[i];
        rep(j,sz[i]) room[i].pb(READ());
        b[i] = READ();
    }

    vector<int> deg(n);
    vector<vector<bool>> touch(n,(vector<bool>(n)));
    vector<VP> cp(n, VP(n));

    // iとjが接する場所
    rep(i,n)rep(j,i){
        bool tmp = false;
        Point pp;
        for(Point p:room[i]){
            rep(k,sz[j])if(isecSP(room[j][k], room[j][(k+1)%sz[j]], p)){
                tmp = true;
                pp = p;
            }
        }
        for(Point p:room[j]){
            rep(k,sz[i])if(isecSP(room[i][k], room[i][(k+1)%sz[i]], p)){
                tmp = true;
                pp = p;
            }
        }

        if(tmp){
            touch[i][j] = touch[j][i] = true;
            ++deg[i];
            ++deg[j];
            cp[i][j] = cp[j][i] = pp;
        }
    }

    vector<vector<double>> d(n, vector<double>(n,INF));
    rep(i,n){
        VP ps;
        ps.pb(b[i]);
        rep(j,sz[i]) ps.pb(room[i][j]);

        int V = sz[i]+1;
        vector<int> idx(n,-1);
        rep(j,n)if(touch[i][j]){
            ps.pb(cp[i][j]);
            idx[j] = V++;
        }

        vector<double> dist(V,INF);
        dist[0] = 0;
        queue<int> que({0});
        while(!que.empty()){
            int a = que.front();
            que.pop();
            rep(j,V)if(j!=a){
                bool can_move = true;
                rep(k,sz[i]){
                    Point p1 = room[i][k], p2 = room[i][(k+1)%sz[i]];
                    if(isecSS(ps[a],ps[j],p1,p2)){
                        Point cand = crosspointLL(ps[a],ps[j],p1,p2);
                        bool edge = false;
                        for(Point ep:{ps[a],ps[j]}){
                            if(abs(ep-cand) < EPS) edge = true;
                        }

                        if(!edge){
                            can_move = false;
                            break;
                        }
                    }
                }
                if(inPolygon( (ps[a]+ps[j])*0.5, room[i] ) == 0) can_move = false;

                if(can_move){
                    double add = abs(ps[a]-ps[j]);
                    if( dist[a]+add+EPS < dist[j] ){
                        dist[j] = dist[a]+add;
                        que.push(j);
                    }
                }
            }
        }

        rep(j,n)if(touch[i][j]) d[i][j] = dist[idx[j]];
    }

    int start = 0;
    rep(i,n)if(deg[i]%2 == 1) start |= (1<<i);
    double s_sum = 0;
    rep(i,n)rep(j,n)if(touch[i][j]) s_sum += d[i][j];

    vector<double> dp(1<<n,INF);
    dp[start] = s_sum;

    using P = pair<double, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({s_sum, start});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int mask = now.se;
        if(now.fi > dp[mask]) continue;

        rep(i,n)rep(j,i)if(touch[i][j]){
            int nx = mask^(1<<i)^(1<<j);
            double add = d[i][j] + d[j][i];
            if(dp[mask]+add+EPS < dp[nx]){
                dp[nx] = dp[mask]+add;
                pq.push({dp[nx], nx});
            }
        }
    }

    printf("%.10f\n", dp[0]);
    return 0;
}
