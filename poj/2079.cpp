#include <cstdio>
#include <iostream>
#include <algorithm>
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
    Point(double x, double y):x(x),y(y){}

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

int n;
Point ps[50000],qs[100000];
int C;

void make_convex_hull()
{
    sort(ps,ps+n);
    int k=0;
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
    C=k-1;
}

double caliper(int b)
{
    double ret=0;
    bool move_i=false;
    int i=0, j=b+1;
    while(1)
    {
        // printf("i= %d, j= %d\n", i,j);
        ret=max(ret,fabs((qs[i]-qs[j]).det(qs[(i+b)%C]-qs[j])/2));
        if((qs[(i+b)%C]-qs[i]).det(qs[(j+1)%C]-qs[j])<0)
        {
            i=(i+1)%C;
            move_i=true;
        }
        else j=(j+1)%C;

        if(move_i && i==0) break;
    }
    return ret;
}

int main()
{
    while(scanf(" %d", &n),(n!=-1))
    {
        rep(i,n) scanf(" %lf %lf", &ps[i].x, &ps[i].y);
        make_convex_hull();

        double ans=0;
        for(int i=1; i<=C/2; ++i) ans=max(ans,caliper(i));
        printf("%.2f\n", ans);
    }
    return 0;
}
