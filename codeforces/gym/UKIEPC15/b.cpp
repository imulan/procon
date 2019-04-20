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

int main(){
    int n;
    double g;
    scanf(" %d %lf", &n, &g);

    dbg(n);
    dbg(g);

    rep(i,n){
        int d,t;
        scanf(" %d %d", &d, &t);
        double a = g*cos(PI*(90-t)/180.0);
        dbg(a);
        // aT^2/2 = d
        // 2d/a = T^2
        double T = sqrt(2.0*d/a);
        printf("%.10f\n", g*T);
    }
    return 0;
}
