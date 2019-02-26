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

double F(double L, double R, double r){
    auto f = [&](double x){
        return (x*sqrt(r*r-x*x) + r*r*asin(x/r))/2.0;
    };
    return f(R) - f(L);
}

int main(){
    double w,h;
    int s;
    while(cin >>w >>h >>s,s){
        if(h>w) swap(h,w);

        auto check = [&](double r){
            double lx = w/2, rx = sqrt(r*r-h*h/4);
            rx = min(rx,w);

            double S = F(lx, rx, r);
            S -= (rx-lx)*h/2;

            if(r > h){
                rx = sqrt(r*r-h*h);
                rx = min(rx,w);
                if(lx<rx){
                    S -= F(lx, rx, r);
                    S += (rx-lx)*h;
                }
            }

            return S*4 >= s;
        };

        double ng = sqrt(w*w+h*h)/2, ok = sqrt(w*w+h*h);
        rep(i,40){
            double mid = (ng+ok)/2;
            if(check(mid)) ok = mid;
            else ng = mid;
        }

        printf("%.10f\n", ok*ok*4);
    }
    return 0;
}
