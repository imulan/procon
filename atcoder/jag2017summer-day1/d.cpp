#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)

int main()
{
    double x,y,z;
    cin>>x>>y>>z;
    double t = atan2(y,x);
    printf("%.10f\n",z*(x*sin(t)+y*cos(t))/(y+z*sin(t)) );
    return 0;
}
