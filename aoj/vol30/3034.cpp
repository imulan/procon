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
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const VP& ps) {
  Point c;
  double move = 0.5;
  rep(i,30) {  // 2^(-39-1) \approx 0.9e-12
    rep(t,30) {
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

Point READ(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

const int N = 14;
const int INF = 19191919;
int dp[1<<N];

int main(){
    int n,m;
    cin >>n >>m;

    VP p(n);
    rep(i,n) p[i] = READ();

    vector<double> r(1<<n);
    for(int mask=1; mask<(1<<n); ++mask){
        VP pts;
        rep(i,n)if(mask>>i&1) pts.pb(p[i]);

        Point c = minEnclosingCircle(pts);
        for(Point pp:pts) r[mask] = max(r[mask], abs(pp-c));
    }

    auto check = [&](double lim){
        rep(i,1<<n) dp[i] = INF;
        dp[(1<<n)-1] = 0;

        for(int mask = (1<<n)-1; mask>0; --mask){
            int sub = mask;
            do{
                sub = sub-1;
                sub &= mask;
                int tgt = mask^sub;
                if(r[tgt] <= lim) dp[sub] = min(dp[sub], dp[mask]+1);
            }while(sub>0);
        }

        return dp[0]<=m;
    };

    double ng=0, ok = 500000;
    rep(loop,100){
        double mid = (ng+ok)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%.10f\n", ok);
    return 0;
}
