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

int n;
int x[14],y[14];
double w[14];

//配送状況，最後に訪れた配送先(0はスタート地点)
double dp[1<<14][14]={0};
double dfs(int mask, int last)
{
    if(dp[mask][last]>=0) return dp[mask][last];

    //配送先から酒屋に帰る
    if(mask==(1<<(n+1))-2)
    {
        return 5.0/6*(abs(x[last]-x[0])+abs(y[last]-y[0]));
    }

    //現在の荷物の重さ
    double W=0;
    for(int i=1; i<=n; ++i) if(!(mask>>i&1)) W+=w[i];
    //かかる時間
    double T=(W+100)/120;

    double ret=1e10;
    //次の配送先
    for(int i=1; i<=n; ++i)
    {
        if(mask>>i&1) continue;
        ret=min(ret,dfs(mask+(1<<i),i)+w[i]+T*(abs(x[i]-x[last])+abs(y[i]-y[last])));
    }

    return dp[mask][last]=ret;
}

int main()
{
    int x0,y0;
    cin >>x0 >>y0;

    cin >>n;
    x[0]=x0;
    y[0]=y0;
    for(int i=1; i<=n; ++i) cin >>x[i] >>y[i] >>w[i];

    fill(dp[0],dp[1<<14],-1);
    printf("%.10lf\n", dfs(0,0));
    return 0;
}
