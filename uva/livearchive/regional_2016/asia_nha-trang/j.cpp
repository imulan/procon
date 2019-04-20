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

const double PI = acos(-1);

inline double sv(double r){
    return r*r*r*PI*4/3;
}

inline double F(double r, double x){
    return PI*(r*r*x - x*x*x/3);
}

double solve(){
    int n;
    double W,L,D,V;
    cin >>n >>W >>L >>D >>V;
    double dH = V/(W*L);

    vector<double> w(n),r(n);
    rep(i,n) cin >>r[i] >>w[i];

    auto height = [&](int idx){
        double ok=-r[idx], ng=r[idx];
        rep(loop,50){
            double x=(ok+ng)/2;
            double tv = F(r[idx],r[idx])-F(r[idx],x);
            if(tv<w[idx]*sv(r[idx])) ng = x;
            else ok = x;
        }
        return r[idx]-ok;
    };

    vector<double> h(n);
    rep(i,n) h[i] = height(i);
    // dbg(h);

    auto valid = [&](double m){
        // dbg(m);
        double vv = V;
        rep(i,n){
            double hh = min(h[i], m);
            double add = F(r[i],r[i]) - F(r[i],r[i]-hh);
            // dbg(add);
            vv += add;
        }
        // vv = min(vv,W*L*D);
        return vv < m*W*L;
    };

    double ng=0, ok=D;
    rep(loop,50){
        double mid = (ng+ok)/2;
        // printf(" %f %f\n", ng, ok);
        if(valid(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) printf("%.10f\n", solve());
    return 0;
}
