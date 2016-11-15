#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int C,D,W,X;
int E[15][30],F[15][30];

int dp[31][51][6];
int dfs(int day, int cost, int x)
{
    if(dp[day][cost][x]>=0) return dp[day][cost][x];
    if(day==D) return 0;

    int ret=0;

    // ライブしない
    ret=max(ret,dfs(day+1,cost,x));

    rep(place,C)
    {
        if(E[place][day]==0) continue;

        // 1回ライブ
        if(cost+F[place][day]<=W) ret=max(ret,dfs(day+1,cost+F[place][day],x)+E[place][day]);

        // 複数回ライブ
        if(x==X) continue;

        int tcost=cost+F[place][day];
        int tE=E[place][day];
        int now=place-1;
        while(now>=0)
        {
            if(E[now][day]==0) break;
            if(tcost+F[now][day]>W) break;

            tcost+=F[now][day];
            tE+=E[now][day];
            ret=max(ret,dfs(day+1,tcost,x+1)+tE);
            --now;
        }

        tcost=cost+F[place][day];
        tE=E[place][day];
        now=place+1;
        while(now<C)
        {
            if(E[now][day]==0) break;
            if(tcost+F[now][day]>W) break;

            tcost+=F[now][day];
            tE+=E[now][day];
            ret=max(ret,dfs(day+1,tcost,x+1)+tE);
            ++now;
        }
    }

    return dp[day][cost][x]=ret;
}

int main()
{
    while(scanf(" %d %d %d %d",&C,&D,&W,&X),C)
    {
        rep(i,C)rep(j,D) scanf(" %d", &E[i][j]);
        rep(i,C)rep(j,D) scanf(" %d", &F[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n", dfs(0,0,0));
    }
    return 0;
}
