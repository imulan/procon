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

#define dbg(x) cout<<#x"="<<x<<endl
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))

int n;
int w[300];

//[i,j]区間を消去可能
int er[301][301];

int dp[301][2];
//現在地now,dr=前の区間が0(削除),1(残す)
int dfs(int now, int dr)
{
    if(dp[now][dr]>=0) return dp[now][dr];
    if(now==n) return 0;

    int ret=0;

    if(dr==0)
    {
        //残す
        for(int i=now; i<n; ++i) ret=max(ret,dfs(i+1,!dr));
    }
    else
    {
        //削除
        for(int i=now+1; i<n; i+=2)
        {
            if(er[now][i]) ret=max(ret,dfs(i+1,!dr)+i-now+1);
        }
    }

    //printf("%d, %d  ret %d\n",now,dr,ret );

    return dp[now][dr]=ret;
}

int main()
{
    while(cin >>n,n)
    {
        //初期化
        memset(er,0,sizeof(er));

        rep(i,n) cin >>w[i];

        rep(i,n-1) if(abs(w[i]-w[i+1])<=1) er[i][i+1]=1;

        for(int b=3; b<n; ++b)
        {
            //左端i
            rep(i,n)
            {
                //右端r
                int r=i+b;
                if(r>=n) break;

                for(int l=i+2; l<r; l+=2)
                {
                    er[i][r] |= er[i][l-1]&er[l][r];
                }
                er[i][r] |= er[i+1][r-1]&(abs(w[i]-w[r])<=1);
            }
        }

        /*
        rep(i,n)for(int j=i; j<n; ++j) printf("er[%d][%d]=%d\n",i,j,er[i][j]);
        */

        memset(dp,-1,sizeof(dp));
        int ans=dfs(0,0);
        memset(dp,-1,sizeof(dp));
        ans=max(ans,dfs(0,1));

        cout << ans << endl;
    }
    return 0;
}
