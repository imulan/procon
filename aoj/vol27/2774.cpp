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
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  //= !ccw(a1, a2, r)
  return min(abs(a1-p), abs(a2-p));
}

const int N = 5001;
double minc[N], minp[N];
int id[N];
bool used[N];

int main()
{
    int n,m;
    cin >>n >>m;
    ++n;

    VP p(n);
    rep(i,n)
    {
        int x,y;
        cin >>x >>y;
        p[i] = Point(x,y);
    }

    fill(minc,minc+N,INF);
    fill(minp,minp+N,INF);
    fill(id,id+N,0);
    fill(used,used+N,false);

    double ans = 0;
    minc[0] = 0;
    minp[0] = 0;

    rep(_,m+1)
    {
        int v = -1;
        rep(i,n)
        {
            if(!used[i] && (v==-1 || minc[i]<minc[v])) v = i;
        }

        // rep(i,n) printf("%d : minp %f minc %f, id %d\n", i,minp[i],minc[i],id[i]);

        if(v==-1) break;
        // dbg(v);
        used[v] = true;
        ans += minp[v];
        rep(i,n)
        {
            // printf("%d - %d  -> %d\n", id[v],v,i);
            minc[i] = min({minc[i],abs(p[v]-p[i]),distSP(p[id[v]],p[v],p[i])});
        }

        rep(i,n)
        {
            if(minp[i] > abs(p[v]-p[i]))
            {
                minp[i] = min(minp[i],abs(p[v]-p[i]));
                id[i] = v;
            }
        }
    }

    printf("%.10f\n", ans);
    return 0;
}
