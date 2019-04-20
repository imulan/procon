#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
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

vector<Point> make_convex_hull(const vector<Point> &points)
{
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

const double INF=1e9;

double pedist(Point &p, Point &a, Point &b)
{
    double k=(p-a).dot(b-a)/(b-a).dot(b-a);

    if(k<0) return p.dist(a);
    if(k>1) return p.dist(b);
    
    Point ph=a-p+(b-a)*k;
    return sqrt(ph.dot(ph));
}

int main()
{
    int n[2];
    while(scanf(" %d %d", &n[0], &n[1]),n[0]|n[1])
    {
        vector<Point> convex[2];
        rep(i,2)
        {
            convex[i]=vector<Point>(n[i]);
            rep(j,n[i]) scanf(" %lf %lf", &convex[i][j].x, &convex[i][j].y);

            convex[i]=make_convex_hull(convex[i]);
            n[i]=convex[i].size();
        }

        int a=0,b=0;

        double td=INF;
        rep(i,n[1])
        {
            double d=convex[0][a].dist(convex[1][i]);
            if(d<td)
            {
                td=d;
                b=i;
            }
        }
        td=INF;
        rep(i,n[0])
        {
            double d=convex[1][b].dist(convex[0][i]);
            if(d<td)
            {
                td=d;
                a=i;
            }
        }

        while(1)
        {
            double min_dist=INF;
            int na=-1, nb=-1;
            for(int i=-1; i<=1; ++i)for(int j=-1; j<=1; ++j)
            {
                int ni=(a+i+n[0])%n[0], nj=(b+j+n[1])%n[1];

                double d=convex[0][ni].dist(convex[1][nj]);
                if(d<min_dist)
                {
                    min_dist=d;
                    na=ni;
                    nb=nj;
                }
            }

            if(na==a && nb==b) break;
            a=na;
            b=nb;
            // printf("a,b %d, %d\n", a,b);
        }

        // printf("a,b %d, %d\n", a,b);
        // printf("(%f,%f) and (%f,%f)\n", convex[0][a].x, convex[0][a].y,convex[1][b].x, convex[1][b].y);

        double ans=convex[0][a].dist(convex[1][b]);

        rep(i,n[0])
        {
            ans=min(ans,pedist(convex[0][i], convex[1][(b-1+n[1])%n[1]], convex[1][b]));
            ans=min(ans,pedist(convex[0][i], convex[1][(b+1+n[1])%n[1]], convex[1][b]));
        }

        rep(i,n[1])
        {
            ans=min(ans,pedist(convex[1][i], convex[0][(a-1+n[0])%n[0]], convex[0][a]));
            ans=min(ans,pedist(convex[1][i], convex[0][(a+1+n[0])%n[0]], convex[0][a]));
        }

        printf("%.5f\n", ans);
    }
    return 0;
}
