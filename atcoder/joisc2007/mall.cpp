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

const int N=1001;

int w,h,X,Y;
int c[N][N],p[N][N]={};
int dp[N][N]={},dp2[N][N]={};

inline int calc(int x, int y, int t)
{
    int ret;
    if(t==1) ret=dp[y+Y-1][x+X-1]-dp[y+Y-1][x-1]-dp[y-1][x+X-1]+dp[y-1][x-1];
    else ret=dp2[y+Y-1][x+X-1]-dp2[y+Y-1][x-1]-dp2[y-1][x+X-1]+dp2[y-1][x-1];
    return ret;
}

int main()
{
    scanf(" %d %d", &w, &h);
    scanf(" %d %d", &X, &Y);
    for(int i=1; i<=h; ++i)for(int j=1; j<=w; ++j)
    {
        scanf(" %d", &c[i][j]);
        if(c[i][j]==-1) p[i][j]=1;
    }
    for(int i=1; i<=h; ++i)for(int j=1; j<=w; ++j)
    {
        dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+c[i][j];
        dp2[i][j] = dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1]+p[i][j];
    }

    int ans=123456789;
    for(int y=1; y<=h-Y+1; ++y)for(int x=1; x<=w-X+1; ++x)
    {
        if(calc(x,y,2)>0) continue;
        ans = min(ans,calc(x,y,1));
    }
    printf("%d\n", ans);
    return 0;
}
