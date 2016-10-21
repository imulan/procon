#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;

int T,n;
int t[30];
int interview[101];

int dp[102][30];
int dfs(int day, int cycle)
{
    if(dp[day][cycle]>=0) return dp[day][cycle];
    if(day==101) return 0;

    // failed
    if(interview[day]<t[cycle]) return INF;

    int ret=INF;

    // take
    ret=min(ret,dfs(day+1,(cycle+1)%T));
    // don't take
    ret=min(ret,dfs(day+1,0)+1);

    return dp[day][cycle]=ret;
}

int main()
{
    while(cin >>T,T)
    {
        fill(interview,interview+101,INF);
        memset(dp,-1,sizeof(dp));

        rep(i,T) scanf(" %d", &t[i]);
        scanf(" %d", &n);
        rep(i,n)
        {
            int d,m;
            scanf(" %d %d", &d, &m);
            interview[d]=min(interview[d],m);
        }

        printf("%d\n", dfs(1,0));
    }
    return 0;
}
