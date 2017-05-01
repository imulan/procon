#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;

int n;
string s;

int dp[101][101];
int dfs(int now, int l)
{
    if(now==n)
    {
        if(l==0) return -1;
        else return INF;
    }

    if(dp[now][l]>=0) return dp[now][l];

    int ret=INF;
    // 打ち切る
    bool can_stop=true;
    int ct=l;
    for(int i=now; i<n; ++i)
    {
        if(s[i]=='(') ++ct;
        else --ct;

        if(ct<0)
        {
            can_stop=false;
            break;
        }
    }
    if(ct!=0) can_stop=false;
    if(can_stop) ret=-1;

    // 次に行く
    if(s[now]=='(')
    {
        ret = min(ret,dfs(now+1,l+1)+1);
        if(l>0) ret = min(ret,dfs(now+1,l-1)+2);
    }
    else
    {
        ret = min(ret,dfs(now+1,l+1)+2);
        if(l>0) ret = min(ret,dfs(now+1,l-1)+1);
    }

    return dp[now][l]=ret;
}

int main()
{
    cin >>s;
    n = s.size();
    memset(dp,-1,sizeof(dp));
    cout << max(0,dfs(0,0)) << endl;
    return 0;
}
