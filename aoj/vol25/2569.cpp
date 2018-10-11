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
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

Point READ_P(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    while(cin >>n,n){
        Point s = READ_P();
        VP c(n);
        rep(i,n) c[i] = READ_P() - s;
        s -= s;

        double theta = atan2(c[0].Y, c[0].X);
        rep(i,n) c[i] = c[i]*polar(1.0, -theta);

        auto get_a = [](double y, double x){
            double ret = atan2(y,x);
            if(ret<0) ret = 2*PI + ret;
            return ret;
        };

        int ans = 0;
        vector<int> p(n);
        rep(i,n) p[i] = i;
        do{
            double l = get_a(c[p[0]].Y, c[p[0]].X), r = get_a(c[(p[0]+1)%n].Y, c[(p[0]+1)%n].X);
            if(l>r) r += 2*PI;

            VP poly = c;
            int add = 1;
            rep(i,n){
                // printf(" %d :: %.10f ~~ %.10f\n",i,l,r);
                int idx = p[i];
                Point pp = poly[idx], qq = poly[(idx+1)%n];
                rep(j,n) poly[j] = reflection(pp,qq,poly[j]);

                if(i<n-1){
                    int nidx = p[i+1];
                    double nl = get_a(poly[nidx].Y, poly[nidx].X), nr = get_a(poly[(nidx+1)%n].Y, poly[(nidx+1)%n].X);
                    // printf("  nl nr  %.10f ~ %.10f\n",nl,nr);

                    if(nr-nl < 0){
                        if(GE(abs(nr-nl),PI)) nr += 2*PI;
                        else swap(nl,nr);
                    }
                    if(GE(abs(nr-nl),PI)){
                        nl += 2*PI;
                        swap(nl,nr);
                    }

                    bool ok = false;
                    for(int j=-1; j<=1; ++j){
                        double nnl = nl+j*2*PI, nnr = nr+j*2*PI;
                        // printf("  nnl nnr  %.10f ~ %.10f\n",nnl,nnr);
                        nnl = max(nnl, l);
                        nnr = min(nnr, r);
                        if(nnr - nnl > EPS){
                            l = nnl;
                            r = nnr;
                            ok = true;
                            break;
                        }
                    }

                    if(!ok){
                        add = 0;
                        break;
                    }
                }
            }

            // dbg(add);
            ans += add;
        }while(next_permutation(all(p)));

        cout << ans << endl;
    }
    return 0;
}
