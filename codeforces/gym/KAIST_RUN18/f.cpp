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

#define X first
#define Y second

using pi = pair<int,int>;
using Point = pair<int,int>;
using VP = vector<Point>;

// a - b
inline Point SUB(Point a, Point b){
    return {a.X-b.X, a.Y-b.Y};
}

// 内積　dot(a,b) = |a||b|cosθ
inline ll dot(Point a, Point b) {
  return (ll)a.X*b.X + (ll)a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
inline ll cross(Point a, Point b) {
  return (ll)a.X*b.Y - (ll)a.Y*b.X;
}

inline ll norm(Point a){
    return (ll)a.X*a.X + (ll)a.Y*a.Y;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
inline int ccw(Point a, Point b, Point c) {
    b = SUB(b,a);
    c = SUB(c,a);
  if (cross(b,c) >  0) return +1;  // counter clockwise
  if (cross(b,c) <  0) return -1;  // clockwise
  if (dot(b,c)   <  0) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 凸包
// 入力1個 -> 空
// 2個以上の全て同じ点 -> 同じもの2つ
VP convexHull(VP &ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
//   sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

// 凸多角形の直径（最遠点対）
ll convexDiameter(const VP& ps) {
  int n = ps.size();
  int i = min_element(ps.begin(), ps.end()) - ps.begin();
  int j = max_element(ps.begin(), ps.end()) - ps.begin();
  int maxI, maxJ;
  ll maxD = 0;
  rep(_, 2*n) {
    // if (maxD < norm( SUB(ps[i],ps[j]) )) {
    //   maxD = norm( SUB(ps[i],ps[j]) );
    //   maxI = i;
    //   maxJ = j;
    // }
    maxD = max(maxD, norm( SUB(ps[i],ps[j]) ));

    if (cross( SUB(ps[i],ps[(i+1) % n]), SUB(ps[(j+1) % n],ps[j])) <= 0) j = (j+1) % n;
    else                                                      i = (i+1) % n;
  }

  return maxD;
}

const int N = 252525;
int k,n;
int x[N],y[N];

vector<int> ux;
int UX;

const int Y_LIM = 1000000000;
vector<pi> yy;

ll farthest(int l, int r){
    if(r-l == 1){
        ll d = yy[l].se - yy[l].fi;
        return d*d;
    }

    VP poly;
    for(int xx=l; xx<r; ++xx){
        poly.pb({ux[xx], yy[xx].fi});
        if(yy[xx].fi != yy[xx].se) poly.pb({ux[xx], yy[xx].se});
    }
    return convexDiameter(convexHull(poly));
}

bool check(ll m){
    int s = 0;
    rep(num,k){
        int t = 1;
        if( farthest(s,s+1)>m ) return false;

        while( s+2*t <= UX && farthest(s,s+2*t)<=m ) t*=2;

        int add = t;
        for(int i=(t>>1); i>0; i>>=1){
            if( s+add+i <= UX && farthest(s,s+add+i)<=m ) add+=i;
        }
        s += add;
        if(s == UX) break;
    }
    return s == UX;
}

int main(){
    scanf(" %d %d", &n, &k);

    rep(i,n){
        scanf(" %d %d", &x[i], &y[i]);
        ux.pb(x[i]);
    }

    sort(all(ux));
    ux.erase( unique(all(ux)), ux.end() );
    UX = ux.size();

    yy = vector<pi>(UX,{Y_LIM,-Y_LIM});
    rep(i,n){
        int idx = lower_bound(all(ux), x[i]) - ux.begin();
        yy[idx].fi = min(yy[idx].fi, y[i]);
        yy[idx].se = max(yy[idx].se, y[i]);
    }

    ll ng=-1, ok=2000000000000000002LL;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%lld\n", ok);
    return 0;
}
