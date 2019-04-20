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

int main(){
    int w,h,n;
    scanf(" %d %d %d", &w, &h, &n);

    double H = (double)h/w;

    vector<double> x;

    double ans = (1.0+H)*(1.0+H)/4;
    rep(i,n){
        auto f = [&](double p){
            double hh = H*p;

            double ret = ans*p*p;
            double L = (hh + (1-p) + H)/2.0;
            ret += L*L;
            ret -= hh*hh/2;

            return ret;
        };

        double l=0, r=1;
        rep(loop,60){
            double m1 = (2*l+r)/3, m2 = (l+2*r)/3;

            if(f(m1) > f(m2)) l = m1;
            else r = m2;
        }

        ans = f(l);
        rep(j,x.size()) x[j] *= l;
        x.pb(l);
    }

    printf("%.10f\n", ans*w*w);
    rep(i,min(n,10)) printf("%.10f\n", x[i]*w);
    return 0;
}
