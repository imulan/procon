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

const double INF = 1e17;
const double T_LIM = 1e9;

int main(){
    int n;
    scanf(" %d", &n);

    double minX[2], maxX[2], minY[2], maxY[2];
    rep(i,2){
        minX[i] = minY[i] = INF;
        maxX[i] = maxY[i] = -INF;
    }

    double lx = INF, rx = -INF;
    double ly = INF, ry = -INF;

    rep(i,n){
        double x,y;
        char c;
        scanf(" %lf %lf %c", &x, &y, &c);
        if(c == 'L' || c == 'R'){
            int idx = 0;
            if(c == 'R') idx = 1;

            ly = min(ly, y);
            ry = max(ry, y);

            minX[idx] = min(minX[idx], x);
            maxX[idx] = max(maxX[idx], x);
        }
        else{
            int idx = 0;
            if(c == 'U') idx = 1;

            lx = min(lx, x);
            rx = max(rx, x);

            minY[idx] = min(minY[idx], y);
            maxY[idx] = max(maxY[idx], y);
        }
    }

    vector<double> cand;
    cand.pb(0);

    // X
    for(double X:{lx,rx}){
        rep(i,2){
            for(double m:{minX[i],maxX[i]}){
                double t = m-X;
                if(i) t = -t;
                if(0<=t && t<T_LIM) cand.pb(t);
            }
        }
    }
    for(double x0:{minX[0],maxX[0]})for(double x1:{minX[1],maxX[1]}){
        double t = (x0-x1)/2;
        if(0<=t && t<T_LIM) cand.pb(t);
    }

    // Y
    for(double Y:{ly,ry}){
        rep(i,2){
            for(double m:{minY[i],maxY[i]}){
                double t = m-Y;
                if(i) t = -t;
                if(0<=t && t<T_LIM) cand.pb(t);
            }
        }
    }
    for(double y0:{minY[0],maxY[0]})for(double y1:{minY[1],maxY[1]}){
        double t = (y0-y1)/2;
        if(0<=t && t<T_LIM) cand.pb(t);
    }

    double ans = INF;
    for(double t:cand){
        double X = max({rx, maxX[0]-t, maxX[1]+t}) - min({lx, minX[0]-t, minX[1]+t});
        double Y = max({ry, maxY[0]-t, maxY[1]+t}) - min({ly, minY[0]-t, minY[1]+t});
        ans = min(ans, X*Y);
    }
    printf("%.10f\n", ans);
    return 0;
}
