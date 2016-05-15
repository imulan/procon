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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

vvi f;
int h,w,c;

int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

int dfs(int col, int num, const vvi &field)
{
    //BFS
    vvi vis(h,vi(w,0));
    //最初の左上の色
    int lu=field[0][0];
    queue<pi> que;
    vis[0][0]=1;
    que.push(pi(0,0));
    while(!que.empty())
    {
        pi now=que.front();
        que.pop();
        rep(i,4)
        {
            int nx=now.se+dx[i], ny=now.fi+dy[i];
            if(0<=nx&&nx<w && 0<=ny&&ny<h)
            {
                if(!vis[ny][nx] && field[ny][nx]==lu)
                {
                    vis[ny][nx]=1;
                    que.push(pi(ny,nx));
                }
            }
        }
    }

    //色を塗る
    vvi nf(field);
    rep(i,h)rep(j,w)
    {
        if(vis[i][j]) nf[i][j]=col;
    }

    int ret=0;
    if(num==6)
    {
        //調べ終わり
        int ct=0;
        rep(i,h)rep(j,w) ct+=vis[i][j];
        return ct;
    }
    else if(num==5)
    {
        //塗り終わり
        //同じ色でdfs
        ret=max(ret,dfs(col,num+1,nf));
    }
    else if(num==4)
    {
        //最後にはcにしないといけない
        ret=max(ret,dfs(c,num+1,nf));
    }
    else
    {
        //次の色を選ぶ
        for(int i=1; i<=6; ++i)
        {
            //同じ色は無駄
            if(i==col) continue;

            ret=max(ret,dfs(i,num+1,nf));
        }
    }

    return ret;
}

int main()
{
    while(scanf(" %d %d %d",&h,&w,&c),h|w|c)
    {
        f=vvi(h,vi(w));
        rep(i,h)rep(j,w) scanf(" %d", &f[i][j]);

        int ans=0;
        for(int i=1; i<=6; ++i) ans=max(ans,dfs(i,1,f));

        printf("%d\n", ans);
    }
    return 0;
}
