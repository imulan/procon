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

typedef pair<double,double> pd;

const double eps=1e-8;
int main()
{
    int n;
    cin >>n;

    vector<pd> p(n);
    rep(i,n) scanf(" %lf %lf", &p[i].fi, &p[i].se);

    if(n%2==1)
    {
        printf("NA\n");
        return 0;
    }

    //gravity point
    pd g=pd(0,0);
    rep(i,n)
    {
        g.fi+=p[i].fi;
        g.se+=p[i].se;
    }
    g.fi/=n;
    g.se/=n;

    bool valid=true;
    rep(i,n/2)
    {
        pd v1=pd(p[i].fi-g.fi,p[i].se-g.se);
        pd v2=pd(p[i+n/2].fi-g.fi,p[i+n/2].se-g.se);

        if(fabs(v1.fi+v2.fi)>=eps || fabs(v1.se+v2.se)>=eps)
        {
            valid=false;
            break;
        }
    }

    if(valid) printf("%lf %lf\n",g.fi,g.se);
    else printf("NA\n");

    return 0;
}
