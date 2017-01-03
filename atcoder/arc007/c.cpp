#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[1<<10];
const int INF=123456;

int main()
{
    string s;
    cin >>s;
    int n=s.size();

    fill(dp,dp+(1<<10),INF);
    dp[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int mask=que.front();
        que.pop();
        rep(i,n)
        {
            int nx=mask;
            rep(j,n)if(s[(i+j)%n]=='o') nx|=(1<<j);
            if(dp[nx]>dp[mask]+1)
            {
                dp[nx]=dp[mask]+1;
                que.push(nx);
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;
    return 0;
}
