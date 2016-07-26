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

int main()
{
    int n;
    cin >>n;

    //実際の盤面
    int a[30][30]={0};
    //現在位置
    int x=0,y=0;
    //右,下,左,上 と回っていく
    int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
    //現在の方向
    int dir=0;

    //値
    for(int i=1; i<=n*n; ++i)
    {
        a[y][x]=i;

        //次の位置に進む
        int nx=x+dx[dir], ny=y+dy[dir];

        //枠の中に収まっていてそこにまだ値が入っていなければOK
        if(0<=nx&&nx<n && 0<=ny&&ny<n && a[ny][nx]==0)
        {
            x=nx;
            y=ny;
        }
        else
        {
            //方向転換する
            dir=(dir+1)%4;
            x+=dx[dir];
            y+=dy[dir];
        }
    }

    rep(i,n)
    {
        rep(j,n)
        {
            if(j) printf(" ");
            printf("%03d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
