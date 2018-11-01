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
const double EPS = 1e-8; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

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


Point READ(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n,m;
    while(cin >>n >>m,n){
        VP c(n);
        vector<double> r(n);
        rep(i,n){
            c[i] = READ();
            cin >>r[i];
        }

        auto isecCC = [&](int a, int b){
            if(r[a] > r[b]) swap(a,b);
            double d = abs(c[a] - c[b]);

            if( r[a]+r[b] < d+EPS ) return false;
            if( d+r[a] < r[b]+EPS ) return false;
            return true;
        };

        using D = pair<double,int>;
        vector<vector<D>> g(n);
        rep(i,n){
            rep(j,n)if(j!=i && isecCC(i,j)){
                Point pp = c[j] - c[i];
                double theta = atan2(pp.Y,pp.X);
                g[i].pb({theta,j});
            }
            sort(all(g[i]));
            // dbg(g[i]);
        }

        // 領域
        vector<VP> pls;

        // (円i, 次に向かう方向)
        vector<vector<bool>> vis(n);
        rep(i,n) vis[i] = vector<bool>(g[i].size());

        using pi = pair<int,int>;
        rep(i,n){
            int GG = g[i].size();
            if(GG==0) continue;
            rep(ii,GG){
                if(vis[i][ii]) continue;

                queue<pi> que;
                stack<int> c_idx;
                vector<bool> in(n);

                in[i] = true;
                c_idx.push(i);
                vis[i][ii] = true;
                que.push({i,ii});
                while(!que.empty()){
                    pi cur = que.front();
                    que.pop();

                    // dbg(cur);

                    int idx = cur.fi;
                    int dir = cur.se;

                    int nidx = g[idx][dir].se;
                    int ndir = -1;
                    int sz = g[nidx].size();
                    rep(j,sz){
                        if(g[nidx][j].se == idx){
                            ndir = (j+1)%sz;
                            break;
                        }
                    }

                    assert(ndir >= 0);
                    if(!vis[nidx][ndir]){
                        if(in[nidx]){
                            VP poly;
                            while(in[nidx]){
                                assert(!c_idx.empty());
                                int st_idx = c_idx.top();
                                c_idx.pop();

                                in[st_idx] = false;
                                poly.pb(c[st_idx]);
                            }

                            pls.pb(poly);
                        }

                        in[nidx] = true;
                        c_idx.push(nidx);
                        vis[nidx][ndir] = true;
                        que.push({nidx,ndir});
                    }
                }

                VP poly;
                while(!c_idx.empty()){
                    int st_idx = c_idx.top();
                    c_idx.pop();

                    in[st_idx] = false;
                    poly.pb(c[st_idx]);
                }
                pls.pb(poly);
            }
        }

        // for(VP poly:pls) dbg(poly);

        auto IN = [&](int idx, Point p){
            double d = abs(p - c[idx]);
            return d < r[idx];
        };

        vector<bool> ans(m,true);
        rep(i,m){
            Point start = READ(), goal = READ();
            bool flg = false;
            rep(j,n){
                if(IN(j,start) || IN(j,goal)) flg = true;
                if( IN(j,start) != IN(j,goal) ) ans[i] = false;
            }

            if(!flg){
                for(VP poly:pls)if(poly.size()>=3){
                    int vs = inPolygon(poly, start);
                    int vg = inPolygon(poly, goal);
                    if( vs != vg ) ans[i] = false;
                }
            }
        }

        rep(i,m){
            if(i) cout << " ";
            cout << (ans[i]?"YES":"NO");
        }
        cout << "\n";
    }
    return 0;
}
