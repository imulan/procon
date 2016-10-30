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

struct Point
{
    double x,y,z;
    double norm2(){ return x*x+y*y+z*z; }
};
typedef Point Vector;

struct Object
{
    Point c;
    int r;
    ll cost;
};

double dist(Point p, Point q)
{
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y)+(p.z-q.z)*(p.z-q.z));
}

const double eps=1e-8;

int main()
{
    int n,Q;
    scanf(" %d %d", &n, &Q);
    vector<Object> a(n);
    rep(i,n)
    {
        double x,y,z;
        int r;
        ll l;
        scanf(" %lf %lf %lf %d %lld",&x,&y,&z,&r,&l);
        a[i]=Object{Point{x,y,z},r,l};
    }
    while(Q--)
    {
        double sx,sy,sz,dx,dy,dz;
        scanf(" %lf %lf %lf %lf %lf %lf",&sx,&sy,&sz,&dx,&dy,&dz);

        Vector v=Vector{dx-sx,dy-sy,dz-sz};
        ll ans=0;
        rep(i,n)
        {
            double t=(double)(v.x*(a[i].c.x-sx)+v.y*(a[i].c.y-sy)+v.z*(a[i].c.z-sz))/(v.norm2());

            if(-eps<t && t<1+eps)
            {
                Point h=Point{sx+t*v.x,sy+t*v.y,sz+t*v.z};
                if(dist(a[i].c,h)<a[i].r+eps) ans+=a[i].cost;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
