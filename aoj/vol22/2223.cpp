#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int h,w;
char c[11][11];

string urdl="URDL";
// URDL
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

int o_ct=0;

#define IN(x,y) (0<=x && x<w && 0<=y && y<h)
string ans;
void dfs(string now, int x, int y, int d)
{
    if(now.size()==o_ct)
    {
        ans=now;
        return;
    }

    for(int i=-1; i<=1; ++i)
    {
        int nd = (d+i+4)%4;
        for(int k=1; k<10; ++k)
        {
            int nx = x+k*dx[nd], ny = y+k*dy[nd];
            if(IN(nx,ny) && c[ny][nx]=='o')
            {
                c[y][x]='.';
                dfs(now+urdl[nd], nx, ny, nd);
                c[y][x]='o';
                break;
            }
        }
    }
}

int main()
{
    scanf(" %d %d", &h, &w);
    rep(i,h) scanf(" %s", c[i]);

    int sx,sy,dir;
    rep(i,h)rep(j,w)
    {
        if(c[i][j]!='.' && c[i][j]!='o')
        {
            sx=j;
            sy=i;

            if(c[i][j]=='U') dir=0;
            else if(c[i][j]=='R') dir=1;
            else if(c[i][j]=='D') dir=2;
            else if(c[i][j]=='L') dir=3;
        }
        else if(c[i][j]=='o') ++o_ct;
    }

    dfs("",sx,sy,dir);
    cout << ans << '\n';
    return 0;
}
