#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline double POW(double x, int n)
{
    double ret=1;
    rep(i,n) ret*=x;
    return ret;
}

inline double F(double x, int a, int b, double t)
{
    double lgx = log(x);
    double pa=POW(x,a-1), pb=POW(lgx,b-1);

    double C = pa*x * pb*lgx - t;
    double D = pa * pb * (a*lgx+b);
    return C/D;
}

const double eps=1e-9;

double X[11][11] = {
    {},
    {0, 5.73, 4.47, 3.93, 3.63, 3.45, 3.33, 3.24, 3.18, 3.121, 3.081},
    {0, 3.012, 2.937, 2.892, 2.862, 2.841, 2.825, 2.813, 2.803, 2.795, 2.789},
    {0, 2.294, 2.375, 2.429, 2.469, 2.498, 2.522, 2.540, 2.556, 2.569, 2.580},
    {0, 1.963, 2.080, 2.163, 2.225, 2.275, 2.315, 2.348, 2.377, 2.401, 2.421},
    {0, 1.773, 1.896, 1.987, 2.059, 2.116, 2.164, 2.205, 2.240, 2.270, 2.296},
    {0, 1.649, 1.771, 1.863, 1.937, 1.997, 2.049, 2.093, 2.131, 2.165, 2.195},
    {0, 1.561, 1.678, 1.769, 1.843, 1.904, 1.957, 2.003, 2.043, 2.079, 2.111},
    {0, 1.496, 1.608, 1.696, 1.768, 1.829, 1.882, 1.929, 1.970, 2.006, 2.039},
    {0, 1.445, 1.552, 1.637, 1.707, 1.768, 1.820, 1.866, 1.907, 1.945, 1.978},
    {0, 1.404, 1.506, 1.588, 1.657, 1.716, 1.767, 1.813, 1.854, 1.891, 1.925}
};

int main()
{
    int m;
    scanf(" %d", &m);
    while(m--)
    {
        int a,b;
        double t;
        scanf(" %d %d %lf", &a, &b, &t);

        double ans;
        if(a==0) ans = exp(pow(t,1.0/b));
        else if(b==0) ans = pow(t,1.0/a);
        else
        {
            double x=X[a][b];
            double oldx=0;

            while(fabs(x-oldx)>eps)
            {
                oldx = x;
                x = x - F(x,a,b,t);
            }

            ans = x;
        }

        printf("%.10f\n", ans);
    }
    return 0;
}
