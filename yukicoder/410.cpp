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
    int px,py,qx,qy;
    cin >>px >>py >>qx >>qy;
    printf("%lf\n", (double)((abs(px-qx)+abs(py-qy)))/2);
    return 0;
}
