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

int main()
{
    int n,k;
    cin >>n >>k;

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    ll sum[100001];
    sum[0]=0;
    for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i-1];

    ll ans=0;
    rep(i,n-k+1) ans+=sum[i+k]-sum[i];

    std::cout << ans << std::endl;
    return 0;
}
