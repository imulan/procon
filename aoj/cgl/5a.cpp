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
const double EPS = 1e-9; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

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

int main(){
    int n;
    cin >>n;

    VP p(n);
    rep(i,n){
        double x,y;
        cin >>x >>y;
        p[i] = Point(x,y);
    }

    printf("%.10f\n", closestPair(p));
    return 0;
}
