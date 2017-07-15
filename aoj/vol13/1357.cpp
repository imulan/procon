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

int main()
{
    int n;
    cin >>n;
    vector<int> r(n);
    rep(i,n) cin >>r[i];

    vector<double> x(n);
    rep(i,n)
    {
        x[i]=r[i];
        rep(j,i)
        {
            double t = x[j]+2*sqrt(r[i]*r[j]);
            x[i] = max(x[i],t);
        }
    }

    double ans = 0;
    rep(i,n) ans = max(ans,x[i]+r[i]);
    printf("%.10f\n", ans);
    return 0;
}
