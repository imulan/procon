#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);

    ll sum=0;
    vector<ll> a(2*n);
    rep(i,n)
    {
        scanf(" %lld", &a[i]);
        a[i+n]=a[i];
        sum+=a[i];
    }

    vector<ll> presum(2*n+1,0);
    for(int i=1; i<=2*n; ++i) presum[i] = presum[i-1]+a[i-1];

    ll ans=0;
    rep(i,n)
    {
        int x = lower_bound(all(presum),presum[i]+sum/3)-presum.begin();
        int y = lower_bound(all(presum),presum[i]+sum*2/3)-presum.begin();
        for(int j=x-1; j<=x+1; ++j)for(int k=y-1; k<=y+1; ++k)
        {
            if(i<j && j<k && j<i+n && k<i+n)
            {
                ll p = presum[j]-presum[i];
                ll q = presum[k]-presum[j];
                ll r = presum[i+n]-presum[k];

                ans = max(ans, min({p,q,r}));
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
