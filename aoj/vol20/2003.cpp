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

//点
class Point
{
    public:
    double x,y;

    Point(double x=0, double y=0): x(x), y(y) {}

    Point operator + (Point p)
    {
        return Point(x+p.x, y+p.y);
    }
    Point operator - (Point p)
    {
        return Point(x-p.x, y-p.y);
    }
    Point operator * (double a)
    {
        return Point(a*x,a*y);
    }

};

//ベクトル
typedef Point Vector;

//線分
struct Segment
{
    Point p1,p2;
};

double dist(Point p0, Point p1)
{
    return sqrt((p0.x-p1.x)*(p0.x-p1.x) + (p0.y-p1.y)*(p0.y-p1.y));
}

//内積
double dot(Vector a, Vector b)
{
    return a.x*b.x+a.y*b.y;
}

//外積
double cross(Vector a, Vector b)
{
    return a.x*b.y-a.y*b.x;
}

double EPS=1e-9;

double norm(Vector a)
{
    return a.x*a.x+a.y*a.y;
}

int ccw(Point p0, Point p1, Point p2)
{
    Vector a=p1-p0, b=p2-p0;
    if(cross(a,b)>EPS) return 1;
    if(cross(a,b)<-EPS) return -1;
    if(dot(a,b)<-EPS) return 2;
    if(norm(a)<norm(b)) return -2;

    return 0;
}

//交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 && ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}
bool intersect(Segment s1, Segment s2)
{
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

Point getCrossPoint(Segment s1, Segment s2)
{
    Vector base=s2.p2-s2.p1;
    double d1=fabs(cross(base, s1.p1-s2.p1));
    double d2=fabs(cross(base, s1.p2-s2.p1));
    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}


//始点からの距離,高架or地下(0/1)
typedef pair<double,int> P;

int main()
{
    int t;
    cin >>t;
    rep(T,t)
    {
        Segment newline;
        cin >>newline.p1.x >>newline.p1.y >>newline.p2.x    >>newline.p2.y;

        int n;
        cin >>n;

        vector<Segment> line(n);
        vector<int> o(n),l(n);
        rep(i,n) cin >>line[i].p1.x >>line[i].p1.y >>line[i].p2.x >>line[i].p2.y >>o[i] >>l[i];

        //cross points
        vector<P> cps;

        //i番目の線分に対して
        rep(i,n)
        {
            //新路線と交差するかどうか
            if(intersect(newline,line[i]))
            {
                Point cp=getCrossPoint(newline,line[i]);
                cps.pb(P(dist(newline.p1,cp),(o[i]==l[i])));
            }
        }

        sort(all(cps));

        int ans=0;
        if(cps.size()>0)
        {
            rep(i,cps.size()-1)
            {
                if(cps[i].se!=cps[i+1].se) ++ans;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
