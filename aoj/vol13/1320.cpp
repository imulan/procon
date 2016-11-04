#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;
int dp[17000][14];

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<string> city(n);
        rep(i,n) cin >>city[i];

        vector<string> s;
        rep(i,n)
        {
            bool isSubstring=false;
            int A=city[i].size();
            rep(j,n)
            {
                if(i==j) continue;

                int B=city[j].size();
                rep(k,B-A+1)
                {
                    if(city[j].substr(k,A)==city[i]) isSubstring=true;
                }
            }

            if(!isSubstring) s.pb(city[i]);
        }

        int S=s.size();

        // s[i],s[j]の順に連結する時、s[i]のsuffixとs[j]のprefixの共通部分の最大長
        int com[14][14]={0};
        rep(i,S)rep(j,S)
        {
            if(i==j) continue;
            int A=s[i].size(), B=s[j].size();
            for(int k=1; k<=min(A,B); ++k)
            {
                if(s[j].substr(0,k)==s[i].substr(A-k,k)) com[i][j]=k;
            }
        }

        fill(dp[0],dp[17000],INF);
        rep(i,S) dp[1<<i][i]=s[i].size();
        for(int mask=1; mask<(1<<S); ++mask)
        {
            rep(i,S)if(mask>>i&1)
            {
                rep(j,S)if(!(mask>>j&1))
                {
                    int add=s[j].size();
                    add-=com[i][j];
                    int nx=mask+(1<<j);

                    dp[nx][j]=min(dp[nx][j],dp[mask][i]+add);
                }
            }
        }

        int ans=INF;
        rep(i,S) ans=min(ans,dp[(1<<S)-1][i]);
        cout << ans << endl;
    }
    return 0;
}
