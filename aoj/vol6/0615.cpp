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
int a[2000];

ll dp[2001][2001];
//左端x,右端yの状態
ll dfs(int x, int y)
{
    if(dp[x][y]>=0) return dp[x][y];

    ll ret=0;
    //残り1個
    if(x==y) return a[x];
    else
    {
        //a[x]を選ぶ
        ll add=a[x];
        int nx=(x-1+n)%n;

        //IOIちゃんが選んで終わり
        if(nx==y) ret=max(ret,add);
        else
        {
            //IOIちゃんは大きい方を選ぶ
            if(a[nx]>a[y])
            {
                int nnx=(nx-1+n)%n;
                ret=max(ret,dfs(nnx,y)+add);
            }
            else
            {
                int ny=(y+1)%n;
                ret=max(ret,dfs(nx,ny)+add);
            }
        }

        //a[y]を選ぶ
        add=a[y];
        int ny=(y+1)%n;

        //IOIちゃんが選んで終わり
        if(x==ny) ret=max(ret,add);
        else
        {
            //IOIちゃんは大きい方を選ぶ
            if(a[x]>a[ny])
            {
                nx=(x-1+n)%n;
                ret=max(ret,dfs(nx,ny)+add);
            }
            else
            {
                int nny=(ny+1)%n;
                ret=max(ret,dfs(x,nny)+add);
            }
        }
    }

    //printf("%d,%d ret %lld\n",x,y,ret);
    return dp[x][y]=ret;
}

int main()
{
    cin >>n;
    rep(i,n) cin >>a[i];

    if(n==1)
    {
        cout << a[0] << endl;
        return 0;
    }
    if(n==2)
    {
        cout << max(a[0],a[1]) << endl;
        return 0;
    }

    memset(dp,-1,sizeof(dp));
    ll ans=0;
    //JOI君が最初にケーキiを取る時
    rep(i,n)
    {
        int l=(i-1+n)%n, r=(i+1)%n;
        //IOIちゃんは大きい方を選ぶ
        if(a[l]>a[r]) l=(l-1+n)%n;
        else r=(r+1)%n;

        ans=max(ans,dfs(l,r)+a[i]);
    }

    cout << ans << endl;
    return 0;
}
