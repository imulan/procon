#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;
const int N=1<<16;

int dp[N];
int AND[16][3][7][7];
int OR[16][3][7][7]={};

int solve()
{
    int n;
    cin >>n;
    vector<int> h(n),w(n);
    rep(i,n) cin >>h[i] >>w[i];

    int c[4][4];
    rep(i,4)
    {
        string s;
        cin >>s;
        rep(j,4)
        {
            if(s[j]=='R') c[i][j]=0;
            else if(s[j]=='G') c[i][j]=1;
            else c[i][j]=2;
        }
    }

    #define IN(x,y) (0<=x && x<4 && 0<=y && y<4)
    rep(i,n)rep(col,3)for(int x=-3; x<=3; ++x)for(int y=-3; y<=3; ++y)
    {
        AND[i][col][x+3][y+3] = N-1;

        rep(dy,h[i])rep(dx,w[i])
        {
            int nx=x+dx, ny=y+dy;
            if(IN(nx,ny))
            {
                int shift = ny*4+nx;
                AND[i][col][x+3][y+3] -= 1<<shift;
                if(col == c[ny][nx]) OR[i][col][x+3][y+3] += 1<<shift;
            }
        }
    }

    fill(dp,dp+N,INF);
    dp[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int mask = que.front();
        que.pop();
        rep(i,n)rep(col,3)for(int x=-3; x<=3; ++x)for(int y=-3; y<=3; ++y)
        {
            int nmask = (mask&AND[i][col][x+3][y+3])|OR[i][col][x+3][y+3];

            if(dp[nmask] > dp[mask]+1)
            {
                que.push(nmask);
                dp[nmask] = dp[mask]+1;

                if(nmask == N-1) return dp[nmask];
            }
        }
    }

    assert(false);
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
