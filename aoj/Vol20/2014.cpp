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

int main()
{
    while(1)
    {
        int w,h;
        string a[50];

        //input
        cin >>w >>h;
        if(w==0) break;
        rep(i,h) cin >>a[i];

        //0:不明,1:黒,2:白,3:両方と衝突,-1:どちらとも衝突しない
        int bw[50][50]={0};
        rep(i,h)rep(j,w)
        {
            if(bw[i][j]==0 && a[i][j]=='.')
            {
                //BFS
                int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
                int vis[50][50]={0};
                queue<pi> que;
                que.push(pi(i,j));
                vis[i][j]=1;

                bool black=false, white=false;
                while(!que.empty())
                {
                    pi p=que.front();
                    que.pop();
                    //printf("ac %d,%d\n",p.fi,p.se);

                    if(a[p.fi][p.se]=='B') black=true;
                    else if(a[p.fi][p.se]=='W') white=true;
                    else
                    {
                        rep(k,4)
                        {
                            int nx=p.se+dx[k], ny=p.fi+dy[k];
                            if(0<=nx&&nx<w && 0<=ny&&ny<h)
                            {
                                if(!vis[ny][nx])
                                {
                                    vis[ny][nx]=1;
                                    que.push(pi(ny,nx));
                                }
                            }
                        }
                    }
                }

                int r=0;
                if(black) r|=1;
                if(white) r|=2;

                if(r==0) r=-1;
                //printf("(%d,%d),r=%d\n",i,j,r);

                rep(k,h)rep(l,w)
                {
                    if(vis[k][l] && a[k][l]=='.') bw[k][l]=r;
                }

            }
        }

        int p=0,q=0;
        rep(i,h)rep(j,w)
        {
            if(bw[i][j]==1) ++p;
            if(bw[i][j]==2) ++q;
        }

        printf("%d %d\n",p,q);
    }

    return 0;
}
