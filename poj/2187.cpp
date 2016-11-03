#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double EPS=1e-10;

double add(double a, double b){
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}

struct Point{
    double x,y;
    Point(){}
    Point(double X, double Y):x(X),y(Y){}

    Point operator + (Point p){
        return Point(add(x,p.x), add(y,p.y));
    }
    Point operator - (Point p){
        return Point(add(x,-p.x), add(y,-p.y));
    }
    Point operator * (double d){
        return Point(d*x, d*y);
    }
    bool operator < (Point p)const{
        if(x!=p.x) return x<p.x;
        return y<p.y;
    }
    double dot(Point p){ // 内積
        return add(x*p.x, y*p.y);
    }
    double det(Point p){ // 外積
        return add(x*p.y, -y*p.x);
    }
    double dist(Point p){
        return sqrt(add((x-p.x)*(x-p.x), (y-p.y)*(y-p.y)));
    }
};

vector<Point> make_convex_hull(const vector<Point> &points){
    vector<Point> ps(points);
    int n=ps.size();
    sort(ps.begin(),ps.end());
    int k=0;
    vector<Point> qs(n*2);
    // 下側凸包
    for(int i=0; i<n; ++i){
        while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
        qs[k++]=ps[i];
    }
    // 上側凸包
    for(int i=n-2,t=k; i>=0; --i){
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}

double caliper(const vector<Point> &points)
{
    vector<Point> convex=make_convex_hull(points);
    int n=convex.size();
    if(n==2) return (convex[0]-convex[1]).dot(convex[0]-convex[1]);

    int i=0, j=0;
    for(int k=0; k<n; ++k)
    {
        if(convex[k]<convex[i]) i=k;
        if(convex[j]<convex[k]) j=k;
    }

    // squared-distance
    double ret=0;
    int si=i,sj=j;
    while(i!=sj || j!=si)
    {
        ret=max(ret,(convex[i]-convex[j]).dot(convex[i]-convex[j]));
        if((convex[(i+1)%n]-convex[i]).det(convex[(j+1)%n]-convex[j])<0) i=(i+1)%n;
        else j=(j+1)%n;
    }
    return ret;
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<Point> p(n);
    rep(i,n) scanf(" %lf %lf", &p[i].x, &p[i].y);

    printf("%.0f\n", caliper(p));
    return 0;
}
