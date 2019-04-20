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

struct hole{
    double r,x,y,z;

    void READ(){
        scanf(" %lf %lf %lf %lf", &r, &x, &y, &z);
        r /= 1000;
        x /= 1000;
        y /= 1000;
        z /= 1000;
    }

    double vol(){
        return r*r*r*PI*4/3;
    }

    double F(double L, double R){
        L -= z;
        R -= z;

        double cl = max(-r,L);
        double cr = min(r,R);

        if(cl>cr) return 0;

        auto g = [&](double b){
            return r*r*b - b*b*b/3;
        };

        return PI*(g(cr)-g(cl));
    }
};

int main(){
    int n,s;
    scanf(" %d %d", &n, &s);

    vector<hole> h(n);
    rep(i,n) h[i].READ();

    double V = 1e6;
    rep(i,n) V -= h[i].vol();
    V /= s;

    double lz = 0;
    rep(i,s){
        auto f = [&](double height){
            double ret = 1e4*height;
            rep(j,n) ret -= h[j].F(lz, lz+height);
            return ret;
        };

        double l=0, r=100-lz;
        rep(loop,50){
            double mid = (l+r)/2;
            if(f(mid)>V) r = mid;
            else l = mid;
        }

        printf("%.10f\n", l);
        lz += l;
    }

    return 0;
}
