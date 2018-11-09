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

const int INF = 1e8;
const double EPS = 1e-8;

int main(){
    int n;
    while(scanf(" %d", &n),n){
        vector<int> x(n),r(n);
        rep(i,n) scanf(" %d %d", &x[i], &r[i]);

        auto check = [&](double a){
            double s = INF, e = -INF;
            rep(i,n){
                if(2*r[i]+EPS < a) continue;
                double theta = asin(a/r[i]/2);
                double dx = r[i]*cos(theta);

                double L = x[i]-dx, R=x[i]+dx;
                // printf(" %d:  %f %f\n",i,L,R);

                if(max(s,L) > min(e,R)){
                    s = L;
                    e = R;
                }
                else{
                    s = min(s,L);
                    e = max(e,R);
                }

                if(e-s>a) return true;
            }
            return false;
        };

        double ok=0, ng=200000;
        rep(loop,80){
            double mid = (ok+ng)/2;
            if(check(mid)) ok = mid;
            else ng = mid;
        }
        printf("%.10f\n", ok);
    }
    return 0;
}
