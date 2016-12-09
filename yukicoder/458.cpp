#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=20000;
bool prime[N+1];
vector<int> p;

int dp[N+1]={};
int nx[N+1]={};

void init()
{
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)if(prime[i])
    {
        for(int j=i*2; j<=N; j+=i) prime[j]=false;
    }

    rep(i,N+1)if(prime[i]) p.pb(i);
}

int main()
{
    init();

    int n;
    scanf(" %d", &n);

    memset(dp,-1,sizeof(dp));
    dp[0]=0;

    rep(i,p.size())
    {
        for(int j=n; j>=0; --j)if(dp[j]>=0 && j+p[i]<=n)
        {
            dp[j+p[i]] = max(dp[j+p[i]], dp[j]+1);
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
