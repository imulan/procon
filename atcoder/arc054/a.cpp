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

int main()
{
    double l,x,y,s,d;
    cin >>l >>x >>y >>s >>d;

    double ans=0;

    if(s<d)
    {
        ans=(d-s)/(x+y);
        if(x<y) ans=min(ans,(s+l-d)/(y-x));
    }
    else if(s>d)
    {
        ans=(d+l-s)/(x+y);
        if(x<y) ans=min(ans,(s-d)/(y-x));
    }

    printf("%.10lf\n", ans);
    return 0;
}
