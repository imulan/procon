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
    double vl,vr,d,w;
    cin >>vl >>vr >>d >>w;

    double t=d/(vl+vr);
    printf("%.10f\n", w*t);
    return 0;
}
