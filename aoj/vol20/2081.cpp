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

const double INF = 1e9;

struct Point{
    double x,y,z;
};

using Vector = Point;
using Line = pair<Point,Point>;

double sq(double z){
    return z*z;
}

double size(Vector v){
    return sqrt(sq(v.x) + sq(v.y) + sq(v.z));
}

double Dot(Point a, Point b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector Cross(Point a, Point b){
    return Vector({a.y*b.z-b.y*a.z, a.z*b.x-b.z*a.x, a.x*b.y-b.x*a.y});
}

double dist(Point a, Point b){
    Vector v({a.x-b.x, a.y-b.y, a.z-b.z});
    return size(v);
}

double distLP(Line l, Point p){
    Vector u({l.fi.x-l.se.x, l.fi.y-l.se.y, l.fi.z-l.se.z});
    double usz = size(u);
    u.x /= usz;
    u.y /= usz;
    u.z /= usz;

    Vector a({p.x-l.fi.x, p.y-l.fi.y, p.z-l.fi.z});
    double sw = Dot(a,u);
    Vector w({sw*u.x, sw*u.y, sw*u.z});

    Point h({l.fi.x+w.x, l.fi.y+w.y, l.fi.z+w.z});
    return dist(p,h);
}

double distLL(Line l, Line m){
    Vector vl({l.fi.x-l.se.x, l.fi.y-l.se.y, l.fi.z-l.se.z});
    Vector vm({m.fi.x-m.se.x, m.fi.y-m.se.y, m.fi.z-m.se.z});

    Vector s({l.fi.x-m.fi.x, l.fi.y-m.fi.y, l.fi.z-m.fi.z});
    Vector t = Cross(vl,vm);
    return abs(Dot(s,t))/size(t);
}

Point READ(){
    double x,y,z;
    cin >>x >>y >>z;
    return {x,y,z};
}

int main(){
    int n;
    while(cin >>n,n){
        Point s = READ(), g = READ();
        vector<Line> l(n);
        rep(i,n){
            l[i].fi = READ();
            l[i].se = READ();
        }

        vector<vector<double>> d(n+2, vector<double>(n+2,INF));

        d[n][n+1] = d[n+1][n] = dist(s,g);
        rep(i,n){
            d[i][n] = d[n][i] = distLP(l[i],s);
            d[i][n+1] = d[n+1][i] = distLP(l[i],g);
        }
        rep(i,n)rep(j,i) d[i][j] = d[j][i] = distLL(l[i], l[j]);

        // rep(i,n+2){
        //     rep(j,n+2) printf(" %.4f", d[i][j]);
        //     printf("\n");
        // }

        rep(k,n+2)rep(i,n+2)rep(j,n+2) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        printf("%.10f\n", d[n][n+1]);
    }
    return 0;
}
