#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
const int INF=123456789;
int dp[200001], nxt[200001];

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> s(n),f(n);
    rep(i,n) scanf(" %d %d", &s[i], &f[i]);

    fill(dp,dp+200001,-INF);
    dp[0+N]=0;
    rep(i,n)
    {
        fill(nxt,nxt+200001,-INF);
        rep(j,200001)
        {
            nxt[j]=max(nxt[j],dp[j]);
            if(j+s[i]<0 || j+s[i]>200000) continue;
            nxt[j+s[i]] = max(nxt[j+s[i]], dp[j]+f[i]);
        }

        rep(j,200001) dp[j]=nxt[j];
    }

    int ans=0;
    rep(i,100001)
    {
        if(dp[i+N]>=0) ans=max(ans,i+dp[i+N]);
    }
    printf("%d\n", ans);
    return 0;
}
