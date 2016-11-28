#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=200000;
int dp[N]={0};

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n-1) scanf(" %d", &a[i]);

    int m;
    scanf(" %d", &m);
    if(m==1)
    {
        scanf(" %d", &a[n-1]);

        dp[n-1]=0;
        for(int i=n-2; i>0; --i) dp[i]=abs(a[i+1]-dp[i+1]);

        printf("%d\n", a[0]-a[1]+dp[1]);
    }

    return 0;
}
