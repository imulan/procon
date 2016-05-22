#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n;
string s;

inline bool nat(int l, int r)
{
    if(l==0 || r==0) return true;

    if(l%3==1) return true;
    else if(l%3==2)
    {
        if(r%3==1) return false;
        else return true;
    }
    else
    {
        if(r%3==0) return true;
        else return false;
    }
}

int dp[100001][10][10];
int dfs(int now, int l, int r)
{
    if(dp[now][l][r]>=0) return dp[now][l][r];

    if(now==n) return 0;

    int ret=n;
    if(s[now-1]-'0'==l)
    {
        //一つ前は左足

        //次も左足
        if(nat(s[now]-'0',r)) ret=min(ret,dfs(now+1,s[now]-'0',r)+1);
        //次は右足
        if(nat(l,s[now]-'0')) ret=min(ret,dfs(now+1,l,s[now]-'0'));
    }
    if(s[now-1]-'0'==r)
    {
        //一つ前は右足

        //次は左足
        if(nat(s[now]-'0',r)) ret=min(ret,dfs(now+1,s[now]-'0',r));
        //次も右足
        if(nat(l,s[now]-'0')) ret=min(ret,dfs(now+1,l,s[now]-'0')+1);
    }

    return dp[now][l][r]=ret;;
}

int main()
{
    while(cin >>s,(s!="#"))
    {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        printf("%d\n",min(dfs(1,s[0]-'0',0),dfs(1,0,s[0]-'0')));
    }
    return 0;
}
