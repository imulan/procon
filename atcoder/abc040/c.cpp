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

int ab(int p)
{
    return (p>0)?p:-p;
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    ll dp[100001]={0};
    dp[0]=0;
    dp[1]=ab(a[1]-a[0]);

    for(int i=2; i<n; ++i)
    {
        dp[i]=min(dp[i-1]+ab(a[i]-a[i-1]),dp[i-2]+ab(a[i]-a[i-2]));
    }

    cout << dp[n-1] << endl;

    return 0;
}
