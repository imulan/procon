#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

double p;

inline double func(double x)
{
    return x + p/(pow(2,x/1.5));
}

int main()
{
    scanf(" %lf", &p);

    double l=0; double r=1000;
    double xl=(2*l+r)/3;
    double xr=(l+2*r)/3;
    rep(i,1000)
    {
        xl=(2*l+r)/3;
        xr=(l+2*r)/3;

        if(func(xl)<func(xr)) r=xr;
        else l=xl;
    }


    printf("%.10lf\n", func((xl+xr)/2));
    return 0;
}
