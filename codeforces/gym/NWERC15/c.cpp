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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

const int N = 1000;
vector<int> G[N];

int main(){
    int w,p;
    cin >>w >>p;

    vector<Point> well(w);
    rep(i,w){
        int x,y;
        cin >>x >>y;
        well[i] = Point(x,y);
    }

    vector<int> s(p);
    vector<Line> pipe(p);
    rep(i,p){
        int x,y;
        cin >>s[i] >>x >>y;
        --s[i];
        pipe[i] = {well[s[i]], Point(x,y)};
    }

    rep(i,p)rep(j,i){
        if(s[i]!=s[j] && isecSS(pipe[i].fi, pipe[i].se, pipe[j].fi, pipe[j].se)){
            G[j].pb(i);
            G[i].pb(j);
        }
    }

    bool valid = true;

    const int D = 101010;
    vector<int> d(p,D);
    rep(i,p)if(d[i]==D){
        vector<int> vis;
        vis.pb(i);
        d[i] = 0;
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int e:G[now]){
                if(d[e] > d[now]+1){
                    d[e] = d[now]+1;
                    que.push(e);
                    vis.pb(e);
                }
            }
        }

        int V = vis.size();
        rep(j,V){
            for(int e:G[vis[j]]) valid &= (abs(d[vis[j]]-d[e])%2==1);
        }
    }

    cout << (valid?"":"im") << "possible" << endl;
    return 0;
}
