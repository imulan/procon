#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
int dp[N+1];
int par[N+1];

int main()
{
    int pw[17];
    pw[0]=1;
    for(int i=1; i<17; ++i) pw[i] = pw[i-1]*2;

    int n;
    cin >>n;

    fill(dp,dp+N+1,123456);
    dp[0]=0;
    par[0]=-1;
    queue<int> que;
    que.push(0);

    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,17)
        {
            int x = v-pw[i], y = v+pw[i];
            if(0<=x && x<=n && dp[x]>dp[v]+1)
            {
                dp[x]=dp[v]+1;
                par[x]=v;
                que.push(x);
            }
            if(0<=y && y<=n && dp[y]>dp[v]+1)
            {
                dp[y]=dp[v]+1;
                par[y]=v;
                que.push(y);
            }
        }
    }

    int now=n;
    int idx=0;
    ll ans=0;
    while(now!=0)
    {
        int p = par[now];
        ll val;
        if(now>p)
        {
            cout << "? " << idx << " " << idx + now-p << endl;
            idx += now-p;

            cin >>val;
            ans += val;
        }
        else
        {
            cout << "? " << idx + now-p << " " << idx << endl;
            idx += now-p;

            cin >>val;
            ans -= val;
        }

        now=par[now];
    }

    cout << "! " << ans << endl;
    return 0;
}
