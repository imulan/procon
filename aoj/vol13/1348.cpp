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

const double INF = 1e10;
const double pi = acos(-1);
const double eps = 1e-8;

int main(){
    double d;
    int n,b;
    cin >>d >>n >>b;

    vector<double> p(n),h(n);
    rep(i,n) cin >>p[i] >>h[i];

    double ans = INF;
    rep(num,b+1){
        double w = d/(num+1);

        auto check = [&](double theta){
            double V = sqrt(w/sin(2*theta));
            // double t = 2*V*sin(theta);
            rep(i,n){
                double pos = p[i];
                while(pos>w) pos -= w;

                double T = pos/(V*cos(theta));
                double H = -T * (T/2 - V*sin(theta));
                if(H<=h[i]) return false;
            }
            return true;
        };

        double l = pi/4, r = pi/2-eps;
        rep(loop,50){
            double m = (l+r)/2;
            if(check(m)) r = m;
            else l =m;
        }

        ans = min(ans, sqrt(w/sin(2*l)));
    }

    printf("%.10f\n", ans);
    return 0;
}
