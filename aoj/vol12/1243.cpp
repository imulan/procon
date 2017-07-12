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

int n;
int f[366];

int cl[3][3]={};

int dx[9]={0,1,2,-1,-2,0,0,0,0};
int dy[9]={0,0,0,0,0,1,2,-1,-2};

#define IN(x,y) (0<=x && x<=2 && 0<=y && y<=2)
int dp[366][3][3][7][7][7][7];
int dfs(int d, int y, int x, int lu, int ru, int lb, int rb)
{
    if(d==n) return 1;
    if(dp[d][y][x][lu][ru][lb][rb]>=0) return dp[d][y][x][lu][ru][lb][rb];

    if(f[d]&cl[y][x]) return 0;

    int ret = 0;
    rep(i,9)
    {
        int ny = y+dy[i], nx = x+dx[i];
        if(!IN(nx,ny)) continue;

        int nlu = lu-1;
        int nru = ru-1;
        int nlb = lb-1;
        int nrb = rb-1;
        if(nx==0 && ny==0) nlu=6;
        if(nx==2 && ny==0) nru=6;
        if(nx==0 && ny==2) nlb=6;
        if(nx==2 && ny==2) nrb=6;

        if(nlu<0 || nru<0 || nlb<0 || nrb<0) continue;

        ret |= dfs(d+1,ny,nx,nlu,nru,nlb,nrb);
    }

    return dp[d][y][x][lu][ru][lb][rb] = ret;
}

int main()
{
    rep(y,3)rep(x,3)
    {
        int p = 4*y+x;
        for(const auto &a:vector<int>({0,1,4,5})) cl[y][x] |= 1<<(p+a);
    }
    while(scanf(" %d", &n),n)
    {
        rep(i,n)
        {
            f[i]=0;
            rep(j,16)
            {
                int a;
                scanf(" %d", &a);
                f[i] |= a<<j;
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n", dfs(0,1,1,5,5,5,5));
    }
    return 0;
}
