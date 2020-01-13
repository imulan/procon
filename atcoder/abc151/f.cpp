#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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

const int L = 100;

int main(){
    int n;
    cin >>n;

    VP p(n);
    rep(i,n){
        int x,y;
        cin >>x >>y;
        p[i] = {x,y};
    }

    auto R = [&](Point c){
        double ret = 0;
        rep(i,n) ret = max(ret, abs(c-p[i]));
        return ret;
    };

    auto calc_y = [&](double x){
        double ly=0, ry=1000;
        rep(loop,L){
            double y1 = (2*ly+ry)/3, y2 = (ly+2*ry)/3;
            if(R({x,y1}) > R({x,y2})) ly = y1;
            else ry = y2;
        }
        return ly;
    };

    double lx=0, rx=1000;
    rep(loop,L){
        double x1 = (2*lx+rx)/3, x2 = (lx+2*rx)/3;
        double y1 = calc_y(x1), y2 = calc_y(x2);

        if(R({x1,y1}) > R({x2,y2})) lx = x1;
        else rx = x2;
    }

    printf("%.15f\n", R({lx, calc_y(lx)}));
    return 0;
}
