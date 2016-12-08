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
    double C,D;
    cin >>C >>D;

    double a=4*(5*C-2*D)/13;

    double ans=0;
    if(a<0) ans=2000*7/2*C;
    else
    {
        double b=-21*a/8+7*C/2;
        if(b<0) ans=1000*4*D;
        else ans=1000*a+2000*b;
    }

    printf("%.10f\n", ans);
    return 0;
}
