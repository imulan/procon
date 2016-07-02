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
vector<int> pre[16];

ll dp[66666];

ll dfs(int mask)
{
    if(dp[mask]>=0) return dp[mask];
    if(mask == (1<<n)-1) return 1;

    ll ret=0;

    rep(i,n)
    {
        if(mask>>i&1) continue;

        bool valid=true;
        rep(j,pre[i].size())
        {
            if(!(mask>>pre[i][j]&1)) valid=false;
        }

        if(valid) ret+=dfs(mask+(1<<i));
    }

    return dp[mask]=ret;
}

int main()
{
    int m;
    cin >>n >>m;
    rep(i,m)
    {
        int x,y;
        cin >>x >>y;
        --x;
        --y;
        pre[y].pb(x);
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0) << endl;
    return 0;
}
