#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef complex<double> P;
typedef vector<P> VP;

const double PI = acos(-1);
const double INF = 1e9;
const double EPS = 1e-9;
#define X real()
#define Y imag()
#define LE(n,m) ((n)-(m) < EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) abs((n)-(m) < EPSs)

double dot(P a, P b){
    return  a.X*b.X + a.Y*b.Y;
}

double cross(P a, P b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

P READ(){
    int x,y;
    scanf(" %d %d", &x, &y);
    return P(x,y);
}

int main(){
    int n;
    scanf(" %d", &n);
    VP p(n);
    rep(i,n) p[i] = READ();

    double ans = INF;
    rep(aa,n)rep(bb,n)if(aa!=bb){
        P a = p[aa], b = p[bb];
        double dx = b.X-a.X, dy = b.Y-a.Y;
        double theta = atan2(dy,dx);

        VP t = p;
        P center = p[aa];
        rep(j,n){
            t[j] -= center;
            t[j] *= polar(1.0, -theta);
        }

        double lx = INF, rx = -INF;
        double ly = INF, ry = -INF;
        rep(j,n){
            lx = min(lx, t[j].X);
            rx = max(rx, t[j].X);
            ly = min(ly, t[j].Y);
            ry = max(ry, t[j].Y);
        }

        ans = min(ans, rx-lx);
        ans = min(ans, ry-ly);
    }

    printf("%.9f\n", ans);
    return 0;
}