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

const long mod=1e9+7;

int h,w;
long a[1000][1000];

int df[4]={1,-1,0,0},ds[4]={0,0,1,-1};

long dp[1000][1000];
long rec(int p, int q)
{
    if(dp[p][q]>=0) return dp[p][q];

    long ret=1;
    rep(i,4)
    {
        int np=p+df[i],nq=q+ds[i];
        if(0<=np&&np<h && 0<=nq&&nq<w)
        {
            if(a[p][q]>a[np][nq])
            {
                ret+=rec(np,nq);
                ret%=mod;
            }
        }
    }

    return dp[p][q]=ret;
}

int main()
{
    cin >>h >>w;
    rep(i,h)rep(j,w) scanf(" %ld", &a[i][j]);

    memset(dp,-1,sizeof(dp));
    long ans=0;
    rep(i,h)rep(j,w)
    {
        ans+=rec(i,j);
        ans%=mod;
    }

    printf("%ld\n",ans);
    return 0;
}
