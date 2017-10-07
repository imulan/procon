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

const int N = 100000;
const double INF = 1e8;

int n;
double c[N],r[N];

inline double SQ(double x){ return x*x; }
double h(double x)
{
    double ret = INF;
    rep(i,n) ret = min(ret, sqrt(SQ(r[i]) - SQ(x-c[i])));
    return ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>c[i] >>r[i];

    double L = -INF, R = INF;
    rep(i,n)
    {
        L = max(L,c[i]-r[i]);
        R = min(R,c[i]+r[i]);
    }

    rep(loop,80)
    {
        double m1 = (2*L+R)/3;
        double m2 = (L+2*R)/3;

        if(h(m1)>h(m2)) R=m2;
        else L=m1;
    }

    printf("%.10f\n", h((L+R)/2));
    return 0;
}
