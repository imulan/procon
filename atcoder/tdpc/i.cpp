#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

bool ok[300][300]={};
int dp[300][2]={};

int solve(string s)
{
    int S=s.size();
    if(S<3) return 0;

    rep(i,S-2) ok[i][i+2]=(s.substr(i,3)=="iwi");
    for(int b=6; b<=S; b+=3)
    {
        rep(i,S-b+1)
        {
            bool u=false;

            u |= (s[i]=='i' && ok[i+1][i+b-3] && s[i+b-2]=='w' && s[i+b-1]=='i');
            u |= (s[i]=='i' && s[i+1]=='w' && ok[i+2][i+b-2] && s[i+b-1]=='i');

            for(int j=3; j<b; j+=3) u |= (ok[i][i+j-1] && ok[i+j][i+b-1]);

            ok[i][i+b-1]=u;
        }
    }

    fill(dp[0],dp[300],0);
    rep(i,S)rep(j,i+1)
    {
        if(ok[j][i])
        {
            int a=0;
            if(j-1>=0) a=dp[j-1][0];

            dp[i][1] = max(dp[i][1], a+(i-j+1)/3);
        }

        if(j-1>=0) dp[i][0] = max(dp[i][0],dp[j-1][1]);
    }

    return max(dp[S-1][0],dp[S-1][1]);
}

int main()
{
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
