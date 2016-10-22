#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline double dist(int x, int y)
{
    return sqrt(x*x+y*y);
}

int main()
{
    int D,E;
    while(cin >>D >>E,D)
    {
        double ans=1e10;
        rep(x,D+1) ans=min(ans,fabs(dist(x,D-x)-E));
        printf("%.10f\n", ans);
    }
    return 0;
}
