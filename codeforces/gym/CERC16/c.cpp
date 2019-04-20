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

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-8;
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) (abs((n)-(m))<EPS)

namespace std{
    bool operator<(const Point a, const Point b){
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c){
    b-=a; c-=a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

VP convexHull(VP ps){
    int n = ps.size(), k=0;
    sort(all(ps));
    VP ch(2*n);
    for(int i=0; i<n; ch[k++] = ps[i++])
      while(k>=2 && ccw(ch[k-2], ch[k-1], ps[i])<=0) --k;
    for(int i=n-2, t=k+1; i>=0; ch[k++] = ps[i--])
      while(k>=t && ccw(ch[k-2], ch[k-1], ps[i])<=0) --k;
    ch.resize(k-1);
    return ch;
}

VP tangentPoints(Point a, double ar, Point p){
    VP ps;
    double sin = ar/abs(p-a);
    if( !LE(sin,1) ) return ps;
    double t = PI/2 - asin(min(sin, 1.0));
    ps.pb( a + (p-a)*polar(sin,t) );
    if(!EQ(sin, 1)) ps.pb( a + (p-a)*polar(sin,-t) );
    return ps;
}

int main(){
    int n;
    string s;
    cin >>n >>s;

    VP poly;
    rep(i,n){
        if(s[i]=='S'){
            rep(x,2)rep(y,2){
                poly.pb(Point(i+x,y));
            }
        }
        else if(s[i] =='T'){
            poly.pb(Point(i,0));
            poly.pb(Point(i+1,0));
            poly.pb(Point(i+0.5, sqrt(3)/2));
        }
        else{
            rep(y,2) poly.pb(Point(i+0.5,y));
        }
    }

    rep(i,n)if(s[i]=='C'){
        rep(j,n)if(s[j]!='C'){
            if(s[j]=='T'){
                Point pp(j+0.5, sqrt(3)/2);
                for(Point ppp:tangentPoints( Point(i+0.5, 0.5), 0.5, pp)) poly.pb(ppp);
            }
        }
    }

    VP h = convexHull(poly);
    int sz = h.size();

    double ans = 0;
    rep(i,sz){
        Point p = h[i], q = h[(i+1)%sz];
        // cout << p << " " << q << endl;
        int PX = p.X, QX = q.X;
        if(PX == QX){
            if(s[PX]=='C'){
                Point c(PX+0.5, 0.5);
                Point pp = p-c, qq = q-c;

                // dbg(PX);
                // dbg("CIRCLE");
                // printf("  %f %f\n",atan2(pp.Y,pp.X) , atan2(qq.Y,qq.X));

                double theta = abs( atan2(pp.Y,pp.X) - atan2(qq.Y,qq.X) );
                ans += theta/2;
                continue;
            }
        }

        double d = abs(p-q);
        if(d<EPS) continue;

        ans += d;
    }

    printf("%.10f\n", ans);
    return 0;
}
