#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=40004;
const int INF=12345678;
int dp[N];

int main()
{
    int n;
    scanf(" %d", &n);
    while(n--)
    {
        int p;
        scanf(" %d", &p);
        vector<int> a(p);
        rep(i,p) scanf(" %d", &a[i]);

        fill(dp,dp+N,INF);
        dp[0]=0;
        rep(i,p)
        {
            int idx = lower_bound(dp,dp+N,a[i])-dp;
            dp[idx]=a[i];
        }

        int ans = lower_bound(dp,dp+N,INF)-dp-1;
        printf("%d\n", ans);
    }
    return 0;
}
