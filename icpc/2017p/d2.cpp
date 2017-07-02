#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(s)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl

const int N=1001000;
const int INF=19191919;
int dp[N];

int check(int n, int x, const vector<int> &s)
{
    fill(dp,dp+N,INF);
    dp[1]=0;

    int idx = 0;
    for(int i=1; i<N; ++i)
    {
        if(idx<n-1 && i==s[idx]) ++idx;

        int add = 1;
        for(int j=-1; j<1; ++j)
        {
            int SS = idx+j;
            if(0<=SS && SS<n)
            {
                if(s[SS]<i+x) add = max(add, x-abs(i-s[SS]));
            }
        }

        int ni = i+add;
        if(ni>N-1) ni=N-1;
        dp[ni] = min(dp[ni],dp[i]+1);
        if(i+1<N) dp[i+1] = min(dp[i+1],dp[i]+1);
    }

    int res = INF;
    for(int i=max(0,s[n-1]-x+1); i<N; ++i) res=min(res,dp[i]+1);

    // printf(" x= %d   res %d\n", x,res);
    // if(x<10) rep(i,10) printf("dp[%d] %d\n", i,dp[i]);
    // printf("CH %d\n", res);
    return res;
}

int main() {
    int n,m;
    while(cin >>n >>m, n)
    {
        vector<int> s(n);
        rep(i,n) cin >>s[i];

        int l=s[0], r=1000100;
        while(r-l>1)
        {
            int x = (l+r)/2;

            int res = check(n,x,s);

            if(res>=m) l=x;
            else r=x;
        }

        if(check(n,l,s)<m) l=-1;
        printf("%d\n", l);
    }
    return 0;
}
