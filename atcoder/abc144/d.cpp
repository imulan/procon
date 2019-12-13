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

const double PI = acos(-1);

int main(){
    int a,b,x;
    scanf(" %d %d %d", &a, &b, &x);

    double ok = 0, ng = 90;
    rep(loop,100){
        double mid = (ok+ng)/2;
        double theta = mid*PI/180;

        double V = a*b*b*0.5/tan(theta);
        if(a*sin(theta) < b*cos(theta)){
            double X = b*cos(theta) - a*sin(theta);
            V = a*a*b - a*a*0.5*(b-X/cos(theta));
        }

        if(x<=V) ok = mid;
        else ng = mid;
    }
    printf("%.15f\n", ok);
    return 0;
}
