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

const double EPS=1e-8;

struct point
{
    double x,y;
};

inline double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        int m;
        scanf(" %d", &m);
        vector<point> v(m);
        rep(i,m) scanf(" %lf %lf", &v[i].x, &v[i].y);

        //最初の点を原点に揃える
        double dx=v[0].x, dy=v[0].y;
        rep(i,m)
        {
            v[i].x-=dx;
            v[i].y-=dy;
        }

        vector<int> ans;

        rep(i,n)
        {
            int z;
            cin >>z;
            vector<point> p(z);
            rep(j,z) scanf(" %lf %lf", &p[j].x, &p[j].y);

            //折れ線の頂点数が違うなら論外
            if(z!=m) continue;

            bool valid=true;

            //最初の点をv[0]にそろえて考察
            vector<point> t(p);
            dx=t[0].x, dy=t[0].y;
            rep(j,z)
            {
                t[j].x-=dx;
                t[j].y-=dy;
            }

            //倍率
            double R=dist(v[1],v[0])/dist(t[1],t[0]);
            if(fabs(R-1.0)<EPS)
            {
                //回転
                if(v[1].x==-t[1].y && v[1].y==t[1].x)
                {
                    //90度
                    rep(j,z)
                    {
                        double tx=t[j].x;
                        double ty=t[j].y;
                        t[j].x=-ty;
                        t[j].y=tx;
                    }
                }
                else if(v[1].x==-t[1].x && v[1].y==-t[1].y)
                {
                    //180度
                    rep(j,z)
                    {
                        double tx=t[j].x;
                        double ty=t[j].y;
                        t[j].x=-tx;
                        t[j].y=-ty;
                    }
                }
                else if(v[1].x==t[1].y && v[1].y==-t[1].x)
                {
                    //270度
                    rep(j,z)
                    {
                        double tx=t[j].x;
                        double ty=t[j].y;
                        t[j].x=ty;
                        t[j].y=-tx;
                    }
                }

                rep(j,z)
                {
                    if(fabs(t[j].x-v[j].x)>EPS || fabs(t[j].y-v[j].y)>EPS) valid=false;
                }

            }
            else valid=false;

            if(!valid)
            {
                valid=true;

                //最後の点をv[0]に揃えて考察
                t=p;
                reverse(all(t));
                dx=t[0].x, dy=t[0].y;
                rep(j,z)
                {
                    t[j].x-=dx;
                    t[j].y-=dy;
                }

                //倍率
                R=dist(v[1],v[0])/dist(t[1],t[0]);
                if(fabs(R-1.0)<EPS)
                {
                    //回転
                    if(v[1].x==-t[1].y && v[1].y==t[1].x)
                    {
                        //90度
                        rep(j,z)
                        {
                            double tx=t[j].x;
                            double ty=t[j].y;
                            t[j].x=-ty;
                            t[j].y=tx;
                        }
                    }
                    else if(v[1].x==-t[1].x && v[1].y==-t[1].y)
                    {
                        //180度
                        rep(j,z)
                        {
                            double tx=t[j].x;
                            double ty=t[j].y;
                            t[j].x=-tx;
                            t[j].y=-ty;
                        }
                    }
                    else if(v[1].x==t[1].y && v[1].y==-t[1].x)
                    {
                        //270度
                        rep(j,z)
                        {
                            double tx=t[j].x;
                            double ty=t[j].y;
                            t[j].x=ty;
                            t[j].y=-tx;
                        }
                    }

                    rep(j,z)
                    {
                        if(fabs(t[j].x-v[j].x)>EPS || fabs(t[j].y-v[j].y)>EPS) valid=false;
                    }

                }
                else valid=false;

            }

            if(valid) ans.pb(i+1);
        }

        for(const auto &x : ans) printf("%d\n",x);
        printf("+++++\n");
    }
    return 0;
}
