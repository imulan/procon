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

int n;
int a[10000],b[10000];
int base;

int dp[10001][2][2];
//現在地now,(now-1,now)は使用済みかどうか(x,y)
int check(int now, int x, int y)
{
    if(dp[now][x][y]>=0) return dp[now][x][y];

    int ret=0;

    int val=a[now];

    if(now==n-1)
    {
        if(x==0) val+=b[now-1];
        if(y==0) val+=b[now];

        ret=(val==base);
    }
    else
    {
        //b[now-1]が未使用なら，絶対使わないといけない
        if(x==0) val+=b[now-1];

        if(y==0)
        {
            if(val==base) ret|=check(now+1,0,0);
            if(val+b[now]==base) ret|=check(now+1,1,0);
            if(val+b[now+1]==base) ret|=check(now+1,0,1);
            if(val+b[now]+b[now+1]==base) ret|=check(now+1,1,1);
        }
        else
        {
            if(val==base) ret|=check(now+1,1,0);
            if(val+b[now+1]==base) ret|=check(now+1,1,1);
        }
    }

    return dp[now][x][y]=ret;
}

int main()
{
    int TIMES;
    cin >>TIMES;
    rep(T,TIMES)
    {
        cin >>n;
        rep(i,n) scanf(" %d", &b[i]);
        rep(i,n) scanf(" %d", &a[i]);

        int ans=-1;

        if(n==1) ans=b[0]+a[0];
        else
        {
            //すべての合計
            ll s=0;
            rep(i,n) s+=a[i]+b[i];

            if(s%n==0)
            {
                base=s/n;
                //printf("base = %d\n", base);
                memset(dp,-1,sizeof(dp));
                if(check(0,1,0)==1) ans=base;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
