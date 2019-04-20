#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

const int N = 64;
const int INF = 19191919;

int n;
string a[128];

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int dp[N][N][N][N];

bool is_candidate(int lx, int ly, int rx, int ry, int X, int Y)
{
    if(a[Y][X]!='x') return false;
    bool ret = true;
    for(int i=lx; i<=rx; ++i) ret &= (a[Y][i]=='x');
    for(int i=ly; i<=ry; ++i) ret &= (a[i][X]=='x');
    return ret;
}

int f(int lx, int ly, int rx, int ry)
{
    if(dp[lx/2][ly/2][rx/2][ry/2]<INF) return dp[lx/2][ly/2][rx/2][ry/2];

    // printf("CALL %d %d %d %d\n", lx,ly,rx,ry);

    bool is_empty=true;
    for(int i=ly; i<=ry; ++i)for(int j=lx; j<=rx; ++j)if(a[i][j]=='x') is_empty = false;
    if(is_empty) return 0;

    int ret = INF;
    for(int i=ly+1; i<ry; i+=2)for(int j=lx+1; j<rx; j+=2)
    {
        // 打つ位置の候補
        if(is_candidate(lx,ly,rx,ry,j,i))
        {
            // printf("  !CANDIDATE %d %d\n", i,j);
            ret = min(ret, 1+f(lx,ly,j-1,i-1)+f(j+1,ly,rx,i-1)+f(lx,i+1,j-1,ry)+f(j+1,i+1,rx,ry));
        }
    }

    return dp[lx/2][ly/2][rx/2][ry/2] = ret;
}

int main()
{
    rep(i,N)rep(j,N)rep(k,N)rep(l,N) dp[i][j][k][l]=INF;

    cin >>n;
    rep(i,n) cin >>a[i];
    cout << f(0,0,n-1,n-1) << endl;
    return 0;
}
