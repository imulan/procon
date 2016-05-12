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

const int N=1000000;

typedef pair<int,int> pi;

//フィールド情報
int field[1000][1000]={0};
//写像(数字→座標)
pi im[N+1];
//素数テーブル
bool prime[N+1];

int n,m;

//最大値
int dp[N+1];
//そのときの経路の最後に通る素数
int last[N+1];

bool inline in(int x, int y)
{
    return (0<=x&&x<1000 && 0<=y&&y<1000);
}

int dfs(int v)
{
    if(dp[v]>=0) return dp[v];

    int ret=0;
    int x=im[v].se;
    int y=im[v].fi;

    int t[3];
    memset(t,-1,sizeof(t));

    rep(i,3)
    {
        if(in(y+1,x+i-1) && field[y+1][x+i-1]<=m)
            t[i]=dfs(field[y+1][x+i-1]);
    }

    ret=max({0,t[0],t[1],t[2]});
    rep(i,3)
    {
        if(ret==t[i]) last[v]=max(last[v],last[field[y+1][x+i-1]]);
    }

    if(prime[v])
    {
        ++ret;
        if(ret==1) last[v]=v;
    }

    return dp[v]=ret;
}

int main()
{
    //素数表作成
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(prime[i]) for(int j=2; i*j<=N; ++j) prime[i*j]=false;
    }

    //フィールド作成
    int h=0,w=0;
    int dir=0;
    int dh[4]={0,1,0,-1}, dw[4]={1,0,-1,0};
    for(int i=N; i>0; --i)
    {
        field[h][w]=i;
        im[i]=pi(h,w);
        h+=dh[dir];
        w+=dw[dir];
        if(!in(h,w) || field[h][w]>0)
        {
            h-=dh[dir];
            w-=dw[dir];
            dir=(dir+1)%4;
            h+=dh[dir];
            w+=dw[dir];
        }
    }

    while(scanf(" %d %d", &m, &n),m|n)
    {
        memset(dp,-1,sizeof(dp));
        memset(last,0,sizeof(last));
        int ans=dfs(n);
        printf("%d %d\n", ans, last[n]);
    }
    return 0;
}
