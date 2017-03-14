#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);

    vector<double> x(n),v(n);
    rep(i,n) scanf(" %lf", &x[i]);
    rep(i,n) scanf(" %lf", &v[i]);

    double l=0, r=1e9;

    rep(loop,100)
    {
        double m = (l+r)/2;

        bool ok = true;
        double xl = x[0]-v[0]*m, xr = x[0]+v[0]*m;

        for(int i=1; i<n; ++i)
        {
            double tl = x[i]-v[i]*m, tr = x[i]+v[i]*m;

            if(xr<tl || tr<xl)
            {
                ok = false;
                break;
            }

            xl = max(xl,tl);
            xr = min(xr,tr);
        }

        if(ok) r=m;
        else l=m;
    }

    printf("%.10f\n", r);
    return 0;
}
