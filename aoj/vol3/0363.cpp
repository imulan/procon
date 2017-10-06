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

int h;
int f[10000][4]={};

bool check(int bit, int shift)
{
    if(bit>>shift & 1) return false;
    if(bit>>(shift+1) & 1) return false;
    return true;
}

int dp[10000][1<<4];
int dfs(int y, int b)
{
    if(dp[y][b]>=0) return dp[y][b];
    if(y==h-1) return 0;

    int nx = 0;
    rep(i,4) nx |= f[y+1][i]<<i;
    int ret = 0;
    // 0個
    ret = max(ret, dfs(y+1,nx));
    // 1個
    rep(i,3)if(check(b,i) && check(nx,i))
    {
        int t = nx;
        t |= 1<<i;
        t |= 1<<(i+1);
        ret = max(ret, dfs(y+1,t)+1);
    }
    // 2個
    if(b==0 && nx==0) ret = max(ret, dfs(y+1,15)+2);

    return dp[y][b] = ret;
}

int main()
{
    int n;
    cin >>h >>n;
    rep(i,n)
    {
        int x,y;
        cin >>x >>y;
        f[y][x] = 1;
    }

    int s = 0;
    rep(i,4) s |= f[0][i]<<i;

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,s) << endl;
    return 0;
}
