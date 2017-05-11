#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int a[100000];
int ct[20]={};
int s[20][100001]={};

int dp[1<<20];

int main()
{
    int n,m;
    cin >>n >>m;
    rep(i,n)
    {
        cin >>a[i];
        --a[i];
        ++ct[a[i]];
    }

    rep(i,m)rep(j,n) s[i][j+1] = s[i][j]+(a[j]==i);
    
    fill(dp,dp+(1<<20),n);
    dp[0]=0;
    rep(i,1<<m)
    {
        int st=0;
        rep(j,m)if(i>>j&1) st+=ct[j];

        rep(j,m)if(!(i>>j&1))
        {
            int num = s[j][st+ct[j]] - s[j][st];
            int nx = i|(1<<j);
            dp[nx] = min(dp[nx],dp[i]+(ct[j]-num));
        }
    }

    cout << dp[(1<<m)-1] << endl;
    return 0;
}
