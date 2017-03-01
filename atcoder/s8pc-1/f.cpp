#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod = 10000;

string a,b;
int c,d;

int n;
int pw[80];

int dp[41][50][721][2][2];
int dfs(int digit, int mod_c, int sum, int la, int sb)
{
    if(dp[digit][mod_c][sum][la][sb]>=0) return dp[digit][mod_c][sum][la][sb];

    if(digit == n/2)
    {
        if(mod_c==0 && sum==d) return 1;
        else return 0;
    }

    int ret = 0;

    int lb=0,rb=9;
    if(la==0) lb=a[digit]-'0';
    if(sb==0) rb=b[digit]-'0';

    for(int i=lb; i<=rb; ++i)
    {
        ret += dfs(digit+1, (mod_c+i*pw[digit]+i*pw[n-1-digit])%c, sum+i*2, la|(a[digit]-'0'<i), sb|(i<b[digit]-'0'));
        ret %= mod;
    }

    return dp[digit][mod_c][sum][la][sb] = ret;
}

int main()
{
    cin >>a >>b >>c >>d;

    n = a.size();

    pw[0]=1%c;
    for(int i=1; i<80; ++i) pw[i]=(pw[i-1]*10)%c;

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0,0,0) << endl;
    return 0;
}
