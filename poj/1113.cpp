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

int main()
{
    int n,L;
    scanf(" %d %d", &n, &L);
    vector<Point> p(n);
    rep(i,n) scanf(" %lf %lf", &p[i].x, &p[i].y);

    double ans=L*2*acos(-1);
    vector<Point> convex=make_convex_hull(p);
    int C=convex.size();
    rep(i,C) ans+=convex[i].dist(convex[(i+1)%C]);
    printf("%.0f\n", ans);
    return 0;
}
