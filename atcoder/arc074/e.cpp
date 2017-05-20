#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int N=303;
const int mod=1e9+7;

int n,m;
vector<pi> c[N];
int dp[N][N][N]={};

int main()
{
    cin >>n >>m;
    rep(i,m)
    {
        int l,r,x;
        cin >>l >>r >>x;
        c[r].pb(pi(l,x));
    }

    dp[1][0][0]=1;
    dp[0][1][0]=1;
    dp[0][0][1]=1;
    rep(i,n+1)
    {
        rep(j,i)rep(k,i)
        {
            bool ok = true;
            for(const auto &p:c[i])
            {
                int l=p.fi;
                int x=p.se;

                int ct=1;
                ct += (l<=j);
                ct += (l<=k);

                if(ct!=x) ok = false;
            }

            if(!ok)
            {
                dp[i][j][k] = 0;
                dp[j][i][k] = 0;
                dp[j][k][i] = 0;
                continue;
            }

            (dp[i+1][j][k]+=dp[i][j][k])%=mod;
            (dp[i][i+1][k]+=dp[i][j][k])%=mod;
            (dp[i][j][i+1]+=dp[i][j][k])%=mod;

            (dp[i+1][i][k]+=dp[j][i][k])%=mod;
            (dp[j][i+1][k]+=dp[j][i][k])%=mod;
            (dp[j][i][i+1]+=dp[j][i][k])%=mod;

            (dp[i+1][k][i]+=dp[j][k][i])%=mod;
            (dp[j][i+1][i]+=dp[j][k][i])%=mod;
            (dp[j][k][i+1]+=dp[j][k][i])%=mod;
        }
    }

    int ans=0;
    rep(i,n)rep(j,n)
    {
        (ans+=dp[n][i][j])%=mod;
        (ans+=dp[i][n][j])%=mod;
        (ans+=dp[i][j][n])%=mod;
    }
    cout << ans << endl;
    return 0;
}
