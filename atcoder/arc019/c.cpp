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
typedef pair<pi,int> P;
const int INF = 12345678;

int R,C,K;
int dp[3][50][50][102];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

bool in(pi z)
{
    return (0<=z.fi&&z.fi<R && 0<=z.se&&z.se<C);
}

int main()
{
    cin >>R >>C >>K;
    vector<string> s(R);
    rep(i,R) cin >>s[i];

    //村，ほこら，城 の位置
    pi p[3];
    rep(i,R)rep(j,C)
    {
        if(s[i][j]=='S') p[0]=pi(i,j);
        if(s[i][j]=='C') p[1]=pi(i,j);
        if(s[i][j]=='G') p[2]=pi(i,j);
    }

    //初期化
    fill(dp[0][0][0], dp[3][0][0], INF);
    //p[i]をスタート地点として
    rep(i,3)
    {
        dp[i][p[i].fi][p[i].se][0]=0;
        //(位置,戦闘回数)を保存してBFS
        queue<P> que;
        que.push(P(p[i],0));
        while(!que.empty())
        {
            P state = que.front();
            que.pop();

            //現在位置
            pi now = state.fi;
            //戦闘回数
            int num = state.se;
            rep(j,4)
            {
                pi nx(now.fi+dy[j], now.se+dx[j]);
                if(in(nx) && s[nx.fi][nx.se]!='T')
                {
                    int nxnum = num;
                    if(s[nx.fi][nx.se]=='E') ++nxnum;
                    if(nxnum>101) continue;

                    if(dp[i][nx.fi][nx.se][nxnum] > dp[i][now.fi][now.se][num]+1)
                    {
                        dp[i][nx.fi][nx.se][nxnum] = dp[i][now.fi][now.se][num]+1;
                        que.push(P(nx,nxnum));
                    }
                }
            }
        }
    }

    //最小値の伝播
    rep(i,3)rep(j,R)rep(k,C)
    {
        int minv=dp[i][j][k][0];
        for(int l=1; l<=K; ++l)
        {
            if(minv > dp[i][j][k][l]) minv=dp[i][j][k][l];
            dp[i][j][k][l]=minv;
        }
    }

    int ans = INF;

    //中継地点Xの位置を固定
    rep(i,R)rep(j,C)
    {
        //木のある位置を中継地点にするのは無理
        if(s[i][j]=='T') continue;

        bool enemy=false;
        if(s[i][j]=='E') enemy=true;

        int v[102];
        fill(v,v+102,INF);

        rep(x,K+1)rep(a,x+1)
        {
            int b=x-a;
            if(enemy) ++b;
            v[x] = min(v[x], dp[0][i][j][a]+2*dp[1][i][j][b]);
        }

        int w[102];
        fill(w,w+102,INF);
        rep(y,K+1)rep(x,y+1)
        {
            int c=y-x;
            if(enemy) ++c;
            w[y] = min(w[y], v[x]+dp[2][i][j][c]);
        }

        rep(y,K+1) ans = min(ans,w[y]);
    }

    if(ans>=INF) ans=-1;
    cout << ans << endl;
    return 0;
}
