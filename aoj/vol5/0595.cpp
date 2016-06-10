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

const int mod=10007;

int dp[1001][8];

//a日目,前日の参加状況b
int dfs(int a, int b)
{
    if(dp[a][b]>=0) return dp[a][b];

    if(a==n) return 1;

    //a日目の責任者
    int res=0;
    if(s[a]=='J') res=0;
    else if(s[a]=='O') res=1;
    else if(s[a]=='I') res=2;

    int ret=0;
    //この日の参加状況を仮定
    for(int i=1; i<=7; ++i)
    {
        //この日の責任者はいないといけない
        //前日との差分で1人は同じ人が必要(鍵のため)
        if((i>>res&1) && (b&i))
        {
            ret+=dfs(a+1,i);
            ret%=mod;
        }
    }

    return dp[a][b]=ret;
}

int main()
{
    cin >>n >>s;
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,1) << endl;
    return 0;
}
