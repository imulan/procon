#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod=1000000009;

int dp[202][1900][2];
int x[2][1900]={0};
int call=0;

void calc(string s)
{
    int S=s.size();
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    rep(i,S)
    {
        rep(j,1900)
        {
            for(int k=0; k<s[i]-'0'; ++k)
            {
                if(j+k<1900) (dp[i+1][j+k][1]+=dp[i][j][0])%=mod;
            }
            if(j+(s[i]-'0')<1900) (dp[i+1][j+(s[i]-'0')][0]+=dp[i][j][0])%=mod;

            rep(k,10)
            {
                if(j+k<1900) (dp[i+1][j+k][1]+=dp[i][j][1])%=mod;
            }
        }
    }
    rep(i,1900) x[call][i]=(dp[S][i][0]+dp[S][i][1])%mod;
    ++call;
}

int main()
{
    string m,d;
    cin >>m >>d;
    calc(m);
    calc(d);

    ll ans=0;
    for(int i=1; i<1900; ++i) (ans+=(ll)x[0][i]*x[1][i])%=mod;
    cout << ans << endl;
    return 0;
}
