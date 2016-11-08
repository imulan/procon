#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double INF=1e9;
const double PI=acos(-1);

int n;
double r,theta;
int x[20],y[20];

// from,now,carrots
double dp[20][20][10001];

double d[20][20];
bool moveable[20][20][20];

inline double dist(int a, int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

inline bool check(int a, int b, int c)
{
    double abx=x[b]-x[a], aby=y[b]-y[a];
    double bcx=x[c]-x[b], bcy=y[c]-y[b];

    double AB=sqrt(abx*abx+aby*aby);
    double BC=sqrt(bcx*bcx+bcy*bcy);
    double dot=abx*bcx+aby*bcy;

    double alpha=acos(dot/AB/BC)*180.0/PI;
    return alpha<=theta;
}

int main()
{
    scanf(" %d %lf %lf", &n, &r, &theta);
    rep(i,n) scanf(" %d %d", &x[i], &y[i]);

    rep(i,20)rep(j,20)rep(k,10001) dp[i][j][k]=INF;
    rep(i,n)rep(j,n) d[i][j]=dist(i,j);
    rep(i,n)rep(j,n)rep(k,n)
    {
        if(i==j || i==k || j==k) continue;
        moveable[i][j][k]=check(i,j,k);
    }

    int ans=0;
    for(int i=1; i<n; ++i)
    {
        if(d[0][i]<r)
        {
            dp[0][i][1]=d[0][i];
            ans=1;
        }
    }

    for(int i=1; i<10000; ++i)
    {
        bool update=false;
        rep(from,n)rep(now,n)
        {
            if(from==now) continue;
            if(dp[from][now][i]>r) continue;
            rep(to,n)
            {
                if(to==from || to==now) continue;
                if(moveable[from][now][to])
                {
                    double add=d[now][to];
                    double tmp=dp[from][now][i]+add;
                    if(tmp<=r && dp[now][to][i+1]>tmp)
                    {
                        dp[now][to][i+1]=tmp;
                        update=true;
                    }
                }
            }
        }
        if(update) ans=i+1;
        else break;
    }

    printf("%d\n", ans);
    return 0;
}
