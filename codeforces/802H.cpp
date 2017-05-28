#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    ll dp[30][8]={};
    dp[0][0]=1;

    rep(i,25)rep(j,8)rep(k,8)if(j<=k) dp[i+1][k]+=dp[i][j];

    ll n;
    cin >>n;

    ll ct[30]={};
    for(int i=25; i>=1; --i)
    {
        ct[i-1] = n/dp[i][7];
        n %= dp[i][7];
    }

    string s="";
    rep(i,25)
    {
        s+="ABCDEFG";
        rep(j,ct[i]) s+="H";
    }
    cout << s << " " << "ABCDEFGH" << endl;
    return 0;
}
