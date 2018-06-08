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

using lll = __int128;

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
ll cross(Point a, Point b) {
  return (ll)a.X*(ll)b.Y - (ll)a.Y*(ll)b.X;
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

/* 多角形 */

// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

//多角形PSのi番目の辺
#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

ll solve(){
    int n;
    cin >>n;

    vector<Point> p(n);
    vector<int> ux;
    rep(i,n){
        int x,y;
        cin >>x >>y;
        p[i] = Point(x,y);
        ux.pb(x);
    }

    sort(all(p));

    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    int sz = ux.size();

    if(sz<=2){
        return 0;
    }

    vector<int> idx(n);
    vector<double> lp(sz,INF),up(sz,-INF);
    rep(i,n){
        idx[i] = lower_bound(all(ux), (int)p[i].X) - ux.begin();
        lp[idx[i]] = min(lp[idx[i]],p[i].Y);
        up[idx[i]] = max(up[idx[i]],p[i].Y);
    }

    vector<lll> lh_pre(sz), uh_pre(sz);
    vector<lll> lh_suf(sz), uh_suf(sz);

    auto REV = [&](){
        // reverse
        rep(j,n) p[j] = Point(-p[j].X, p[j].Y);
        sort(all(p));
        rep(j,sz) ux[j] = -ux[j];
        sort(all(ux));
        idx = vector<int>(n);
        lp = vector<double>(sz,INF);
        up = vector<double>(sz,-INF);
        rep(j,n){
            idx[j] = lower_bound(all(ux), (int)p[j].X) - ux.begin();
            lp[idx[j]] = min(lp[idx[j]],p[j].Y);
            up[idx[j]] = max(up[idx[j]],p[j].Y);
        }
    };

    auto CALC = [&](vector<lll> &LH, vector<lll> &UH){
        // lower_hull
        int k = 0;
        VP ch(2*n);
        int i = 0;
        lll t_area = 0;
        while(i<n){
            ch[k] = p[i];
            if(k>0) t_area += cross(ch[k-1], ch[k]);
            if( EQ( abs(p[i] - Point(ux[idx[i]], lp[idx[i]])) , 0) ) LH[idx[i]] = t_area;

            ++k;
            ++i;
            if(i==n) break;

            while (k >= 2 && ccw(ch[k-2], ch[k-1], p[i]) <= 0){
                t_area -= cross(ch[k-2], ch[k-1]);
                --k;
            }
        }

        // upper_hull
        k = 0;
        ch = VP(2*n);
        i = n-1;
        t_area = 0;
        while(i>=0){
            ch[k] = p[i];
            if(k>0) t_area += cross(ch[k-1], ch[k]);
            if( EQ( abs(p[i] - Point(ux[idx[i]], up[idx[i]])) , 0) ) UH[idx[i]] = t_area;

            ++k;
            --i;
            if(i==0) break;

            while (k >= 2 && ccw(ch[k-2], ch[k-1], p[i]) <= 0){
                t_area -= cross(ch[k-2],ch[k-1]);
                --k;
            }
        }
    };

    // lh_pre, uh_suf
    CALC(lh_pre, uh_suf);

    // reverse
    REV();

    // lh_suf, uh_pre
    CALC(lh_suf, uh_pre);
    reverse(all(lh_suf));
    reverse(all(uh_pre));

    // reverse
    REV();

    // answer
    lll ans = LLONG_MAX;
    ll addL = cross(Point(ux[0],up[0]), Point(ux[0],lp[0]));
    ll addR = cross(Point(ux[sz-1],lp[sz-1]), Point(ux[sz-1],up[sz-1]));
    rep(j,sz-1){
        lll tl = addL + lh_pre[j] + uh_pre[j] + cross(Point(ux[j],lp[j]), Point(ux[j],up[j]));
        lll tr = addR + lh_suf[j+1] + uh_suf[j+1] + cross(Point(ux[j+1],up[j+1]), Point(ux[j+1],lp[j+1]));

        ans = min(ans, tl+tr);
    }

    ll ret = (ans+1)/2;
    return ret;
}

int main(){
    printf("%lld\n", solve());
    return 0;
}
