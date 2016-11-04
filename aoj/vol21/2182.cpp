#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[80001][11];

int main()
{
    string s;
    while(cin >>s,(s!="0"))
    {
        memset(dp,0,sizeof(dp));

        int S=s.size();

        if(s[0]!='0') dp[0][s[0]-'0']=1;
        for(int i=1; i<S; ++i)
        {
            int d=s[i]-'0';
            if(d!=0) ++dp[i][d];

            rep(j,11)
            {
                int v=(j*10+d)%11;
                dp[i][v]+=dp[i-1][j];
            }
        }

        int ans=0;
        rep(i,S) ans+=dp[i][0];
        cout << ans << endl;
    }
    return 0;
}
