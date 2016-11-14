#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<pd,pi> pp;

const double EPS=1e-18;

double x[100],y[100],r[100];
vector<pp> cross;

inline double dist(int i, int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

inline bool isCovered(int i, int j)
{
    if(r[j]>r[i]) return dist(i,j)<=r[j]-r[i];
    return false;
}

inline vector<pd> calcCrossPoints(int i, int j)
{

    if(dist(i,j)>(r[i]+r[j]) || isCovered(i,j) || isCovered(j,i)) return vector<pd>();

    vector<pd> ret;
    double A = 2*(x[j]-x[i]);
    double B = 2*(y[j]-y[i]);
    double C = x[i]*x[i] - x[j]*x[j] + y[i]*y[i] - y[j]*y[j] - r[i]*r[i] + r[j]*r[j];

    // printf("A,B,C || %.20f %.20f %.20f\n", A,B,C);

    if(fabs(B)<EPS)
    {
        // x=const.
        double X=-C/A;

        double D = r[i]*r[i] - (X-x[i])*(X-x[i]);
        ret.pb(pd(X,y[i]-sqrt(D)));
        ret.pb(pd(X,y[i]+sqrt(D)));
    }
    else
    {
        // y=ax+b
        double a=-A/B, b=-C/B;
        // printf("A,B,C || %.20f %.20f %.20f\n", A,B,C);
        // printf("a= %f b= %f \n", a,b);
        double P = a*a + 1;
        double Q = a*b - x[i] - a*y[i];
        double R = x[i]*x[i] + (b-y[i])*(b-y[i]) - r[i]*r[i];

        double D=Q*Q-P*R;

        double x1 = (-Q-sqrt(D))/P ,x2 = (-Q+sqrt(D))/P;
        double y1 = a*x1+b, y2 = a*x2+b;

        ret.pb(pd(x1,y1));
        ret.pb(pd(x2,y2));
    }

    // printf("calcCrossPoints(%d , %d)\n", i,j);
    // rep(k,ret.size()) printf(" %f %f\n", ret[k].fi,ret[k].se);
    return ret;
}

inline bool inCircle(int i, pd p)
{
    double dx=x[i]-p.fi, dy=y[i]-p.se;
    double d=sqrt(dx*dx+dy*dy);
    return d<=r[i];
}


int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        rep(i,n) scanf(" %lf %lf %lf", &x[i], &y[i], &r[i]);

        cross.clear();
        rep(i,n)rep(j,i)
        {
            vector<pd> cr=calcCrossPoints(j,i);
            rep(k,cr.size()) cross.pb(pp(cr[k],pi(j,i)));
        }


        int ans=1;
        for(int i=n-2; i>=0; --i)
        {
            // 上にある円で完全に覆われないかチェック
            bool cov=false;
            for(int j=i+1; j<n; ++j)
            {
                if(isCovered(i,j)) cov=true;
            }
            if(cov) continue;

            bool exist=false;
            rep(j,cross.size())
            {
                int a=cross[j].se.fi, b=cross[j].se.se;
                if(a<i || b<i) continue;
                if(inCircle(i,cross[j].fi)) exist=true;
            }

            if(!exist)
            {
                // printf("   !!!!!!exist  %d\n", i);
                ++ans;
                continue;
            }

            // printf("check start i= %d\n", i);
            rep(j,cross.size())
            {
                if(!inCircle(i,cross[j].fi)) continue;

                int a=cross[j].se.fi, b=cross[j].se.se;
                // printf("(%f,%f) , %d,%d\n", cross[j].fi.fi,cross[j].fi.se,a,b);

                bool hidden=false;
                for(int k=i+1; k<n; ++k)
                {
                    if(k==a || k==b) continue;
                    if(inCircle(k,cross[j].fi))
                    {
                        hidden=true;
                        break;
                    }
                }

                if(!hidden)
                {
                    // printf("   !!!!!! hidden  i= %d\n", i);
                    // printf(" (%f,%f)\n", cross[j].fi.fi,cross[j].fi.se);

                    ++ans;
                    break;
                }
            }
        }

        // cout <<" SIZE "<<cross.size()<<endl;
        // rep(i,cross.size()) printf(" %.10f  %.10f\n", cross[i].fi.fi, cross[i].fi.se);
        printf("%d\n", ans);
    }
    return 0;
}
