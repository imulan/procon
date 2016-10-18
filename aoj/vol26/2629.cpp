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
    double d;
    cin >>d;

    double ans=sqrt(2)*d;
    for(int y=1; y<=(int)d; ++y)
    {
        double x=sqrt(d*d-y*y);
        if(x<1) ans=max(ans,(double)y+1);
    }

    printf("%.15lf\n", ans);
    return 0;
}
