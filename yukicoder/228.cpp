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

bool in(int x, int y)
{
    return (0<=x&&x<4 && 0<=y&&y<4);
}

int main()
{
    int a[4][4];
    bool c=true;

    rep(i,4)rep(j,4)
    {
        scanf(" %d", &a[i][j]);
        if(a[i][j]==0) continue;

        int t=a[i][j]-1;
        int di=t/4;
        int dj=t%4;
        int md=abs(i-di)+abs(j-dj);

        if(md>1) c=false;
    }

    if(!c)
    {
        std::cout << "No" << std::endl;
        return 0;
    }

    pi start;
    rep(i,4)rep(j,4) if(a[i][j]==0) start=pi(i,j);

    //そのパネルを動かしたか
    int move[16]={0};
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    queue<pi> que;
    que.push(start);
    while(!que.empty())
    {
        pi now=que.front();
        que.pop();

        //printf(" %d,%d\n", now.fi,now.se);

        if(now==pi(3,3)) break;

        //nowの位置にあるべき数字
        int num=now.fi*4+now.se+1;
        //4近傍にあるか探す
        rep(i,4)
        {
            bool found=false;
            int nx=now.se+dx[i], ny=now.fi+dy[i];
            if(in(nx,ny))
            {
                int val=a[ny][nx];
                if(val==num && move[val]==0)
                {
                    found=true;
                    ++move[val];
                    que.push(pi(ny,nx));
                    swap(a[ny][nx],a[now.fi][now.se]);
                }
            }

            if(found) break;
        }
    }

    bool valid=true;
    rep(i,4)rep(j,4)
    {
        int tmp=i*4+j+1;
        tmp%=16;
        if(a[i][j]!=tmp) valid=false;
    }

    string ans="No";
    if(valid) ans="Yes";
    cout << ans << endl;
    return 0;
}
