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

typedef pair<int,int> pi;

const int N=1000000;

//素数表
bool p[N+1];
//フィールド
int f[1100][1100]={0};
//座標を保存
vector<pi> d(2*N);

//そこを始点とする時の得られる素数の個数の最大値
int dp[N+1];
//dp[i]の値を得られるときに経路上にある最後の素数
int last[N+1];

int main()
{
    //素数表作成
    fill(p,p+N+1,true);
    p[0]=p[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(p[i]) for(int j=2; i*j<=N; ++j) p[i*j]=false;
    }

    //スタート地点
    pi c(525,525);
    //1からスタート
    int now=1;

    //フィールド生成
    f[c.fi][c.se]=now;
    d[now]=c;
    ++now;
    int w=1;
    while(now<=N)
    {
        //右にw
        rep(i,w)
        {
            ++c.se;
            f[c.fi][c.se]=now;
            d[now]=c;
            ++now;
        }

        //上にw
        rep(i,w)
        {
            --c.fi;
            f[c.fi][c.se]=now;
            d[now]=c;
            ++now;
        }

        //左にw+1
        rep(i,w+1)
        {
            --c.se;
            f[c.fi][c.se]=now;
            d[now]=c;
            ++now;
        }

        //下にw+1
        rep(i,w+1)
        {
            ++c.fi;
            f[c.fi][c.se]=now;
            d[now]=c;
            ++now;
        }

        w+=2;
    }

    //クエリ処理
    while(1)
    {
        int m,n;

        scanf(" %d %d", &m, &n);
        if(m==0) break;

        memset(dp,0,sizeof(dp));
        memset(last,0,sizeof(last));

        rep(i,m+1) if(p[i]) last[i]=i;

        for(int y=1100-1-1; y>0; --y)rep(x,1100)
        {
            int cur=f[y][x];
            if(cur==0 || cur>m) continue;

            //printf("  focus %d\n", cur);

            if(p[cur])
            {
                ++dp[cur];
                if(dp[cur]==1) last[cur]=cur;
            }

            for(int dir=-1; dir<=1; ++dir)
            {
                int nx=x+dir;
                int ny=y-1;

                if(0<=nx && nx<1100)
                {
                    int nxnum=f[ny][nx];
                    if(nxnum>m) continue;

                    if(dp[nxnum]<dp[cur])
                    {
                        dp[nxnum]=dp[cur];
                        last[nxnum]=last[cur];

                        //printf("update %d : %d, %d\n", nxnum,dp[nxnum],last[nxnum]);
                    }
                    else if(dp[nxnum]==dp[cur] && last[nxnum]<last[cur])
                    {
                        last[nxnum]=last[cur];
                        //printf("update'' %d : , %d\n", nxnum,last[nxnum]);
                    }
                }
            }
        }

        printf("%d %d\n", dp[n], last[n]);
    }

    return 0;
}
