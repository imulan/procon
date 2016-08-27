#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

int n,S;
string s;

ll dp[301][301][301];
ll dfs(int now, int len, int cor)
{
    if(dp[now][len][cor]>=0) return dp[now][len][cor];

    if(now==n)
    {
        if(len==S && cor==S) return 1;
        else return 0;
    }

    ll ret=0;

    if(len==cor)
    {
        if(cor==S) (ret+=2*dfs(now+1, len+1, cor))%=mod;
        else
        {
            (ret+=dfs(now+1, len+1, cor+1))%=mod;
            (ret+=dfs(now+1, len+1, cor))%=mod;
        }
        //削除
        (ret+=dfs(now+1, max(0,len-1), max(0,cor-1)))%=mod;
    }
    else
    {
        (ret+=2*dfs(now+1, len+1, cor))%=mod;
        //削除
        (ret+=dfs(now+1, max(0,len-1), cor))%=mod;
    }

    return dp[now][len][cor]=ret;
}

int main()
{
    cin >>n >>s;
    S=s.size();

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0,0) << endl;
    return 0;
}
