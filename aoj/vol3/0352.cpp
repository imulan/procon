#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 1001;
const int INF = 1234567890;

int w,h;
int s[N][N]={};
int ps[N][N]={};

int dp[N][N][2];
int dfs(int y, int x, int t)
{
    if(dp[y][x][t] != -INF) return dp[y][x][t];
    if(x==w) return 0;

    int ret;
    if(t==0)
    {
        ret = -INF;
        // down
        if(y+1<=h) ret = max(ret, dfs(y+1,x,!t));
        // right
        if(x+1<=w)
        {
            int diff = 2*ps[y][x+1] - ps[h][x+1];
            ret = max(ret,dfs(y,x+1,!t) + diff);
        }
    }
    else
    {
        ret = INF;
        // down
        if(y+1<=h) ret = min(ret, dfs(y+1,x,!t));
        // right
        if(x+1<=w)
        {
            int diff = 2*ps[y][x+1] - ps[h][x+1];
            ret = min(ret,dfs(y,x+1,!t) + diff);
        }
    }

    return dp[y][x][t] = ret;
}

int main()
{
    scanf(" %d %d", &w, &h);
    rep(i,h)rep(j,w) scanf(" %d", &s[i+1][j+1]);

    // prefix sum (vertical)
    rep(i,w+1)
    {
        for(int j=1; j<=h; ++j) ps[j][i] = ps[j-1][i]+s[j][i];
    }

    rep(i,N)rep(j,N)rep(k,2) dp[i][j][k] = -INF;
    printf("%d\n", abs(dfs(0,0,0)));
    return 0;
}
