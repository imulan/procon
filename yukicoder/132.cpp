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

struct pt{double x,y,z;};
typedef pt vec;

vec make_vec(pt a, pt b)
{
    vec ret;
    ret.x = b.x-a.x;
    ret.y = b.y-a.y;
    ret.z = b.z-a.z;
    return ret;
}

vec cross(vec a, vec b)
{
    vec ret;
    ret.x = a.y*b.z - a.z*b.y;
    ret.y = a.z*b.x - a.x*b.z;
    ret.z = a.x*b.y - a.y*b.x;
    return ret;
}

double dist(double a, double b, double c, double d, pt p)
{
    double nu = abs(a*p.x + b*p.y + c*p.z + d);
    double de = sqrt(a*a + b*b + c*c);
    return nu/de;
}

int main()
{
    int n;
    cin >>n;
    pt p;
    cin >>p.x >>p.y >>p.z;
    vector<pt> q(n);
    rep(i,n) cin >>q[i].x >>q[i].y >>q[i].z;

    double ans=0;

    rep(k,n)rep(j,k)rep(i,j)
    {
        vec h = cross(make_vec(q[j],q[i]), make_vec(q[k],q[i]));
        //平面の式
        double A=h.x, B=h.y, C=h.z;
        double D = -(h.x*q[i].x + h.y*q[i].y + h.z*q[i].z);
        ans += dist(A,B,C,D,p);
    }

    printf("%.10lf\n", ans);
    return 0;
}
