#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=1024;
const double INF=1e12;

double cost[N][N];

int main()
{
    int x[N],y[N],t[N],r[N];
    double d[N];
    int used[N]={};

    int n;
    scanf(" %d", &n);
    rep(i,n) scanf(" %d %d %d %d", &x[i], &y[i], &t[i], &r[i]);

    rep(i,n)rep(j,n) cost[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))/min(t[i],r[j]);

    fill(d,d+n,INF);
    d[0]=0;
    while(1)
    {
        int v=-1;
        rep(i,n)if(!used[i] && (v==-1 || d[i]<d[v])) v=i;

        if(v==-1) break;

        used[v]=1;
        rep(i,n) d[i]=min(d[i],d[v]+cost[v][i]);
    }

    double ans=0;
    sort(d,d+n,greater<double>());
    rep(i,n-1) ans = max(ans,d[i]+i);
    printf("%.7f\n", ans);
    return 0;
}
