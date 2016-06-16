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

const double eps=1e-8;
typedef pair<double,double> p;

double dist(p a, p b)
{
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}

double size(p a)
{
    return sqrt(a.fi*a.fi+a.se*a.se);
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<p> v(n);
        rep(i,n) scanf(" %lf %lf", &v[i].fi, &v[i].se);

        int ans=1;
        //select 2 points
        rep(i,n)rep(j,i)
        {
            double d=dist(v[i],v[j]);
            if(d>2.0) continue;

            double r=sqrt(1.0 - (d*d/4.0));

            double X=v[j].fi-v[i].fi, Y=v[j].se-v[i].se;

            p v1=p(X,Y);
            double v1size=size(v1);
            v1.fi/=v1size; v1.se/=v1size;
            v1.fi*=d/2; v1.se*=d/2;

            p v2;
            double v2size;
            p c;

            //2 candidate for center of circle
            //first
            int ct=0;
            v2=p(-Y,X);
            v2size=size(v2);
            v2.fi/=v2size; v2.se/=v2size;
            v2.fi*=r; v2.se*=r;

            c.fi=v[i].fi+v1.fi+v2.fi; c.se=v[i].se+v1.se+v2.se;
            assert(dist(c,v[i]));
            rep(k,n)
            {
                if(k==i || k==j) ++ct;
                else
                {
                    if(dist(c,v[k])<1.0) ++ct;
                }
            }
            ans=max(ans,ct);

            //second
            ct=0;
            v2=p(Y,-X);
            v2size=size(v2);
            v2.fi/=v2size; v2.se/=v2size;
            v2.fi*=r; v2.se*=r;

            c.fi=v[i].fi+v1.fi+v2.fi; c.se=v[i].se+v1.se+v2.se;
            assert(dist(c,v[i]));
            rep(k,n)
            {
                if(k==i || k==j) ++ct;
                else
                {
                    if(dist(c,v[k])<1.0) ++ct;
                }
            }
            ans=max(ans,ct);
        }

        cout << ans << endl;
    }
    return 0;
}
