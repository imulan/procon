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

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const VP& ps) {
  Point c;
  double move = 0.5;
  rep(i,25) {  // 2^(-39-1) \approx 0.9e-12
    rep(t,40) {
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

bool check(vector<double> &a, vector<double> &b){
    int A = a.size(), B = b.size();
    sort(all(a));
    sort(all(b));

    int j = 0;
    rep(i,A){
        while(j<B){
            if(LE(a[i],b[j])) break;
            ++j;
        }
        if(j==B) return false;
        ++j;
    }
    return true;
}


int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> r(n);
    rep(i,n) scanf(" %d", &r[i]);

    vector<double> pr(m);
    rep(i,m){
        int p;
        scanf(" %d", &p);

        VP poly;
        rep(j,p){
            int x,y;
            scanf(" %d %d", &x, &y);
            poly.pb(Point(x,y));
        }

        Point c = minEnclosingCircle(poly);
        rep(j,p) pr[i] = max(pr[i], abs(c-poly[j]));
    }

    vector<bool> used(n);
    vector<int> ans(m,-1);

    rep(i,m){
        rep(j,n){
            if(used[j] || pr[i]>r[j]+EPS) continue;

            vector<double> a,b;
            for(int k=i+1; k<m; ++k) a.pb(pr[k]);
            rep(k,n)if(!used[k] && k!=j) b.pb(r[k]);

            if(check(a,b)){
                used[j] = true;
                ans[i] = j;
                break;
            }
        }

        if(ans[i]==-1){
            printf("NG\n");
            return 0;
        }
    }

    rep(i,m) printf("%d\n", ans[i]+1);
    return 0;
}
