#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=1234567890123456LL;

int main()
{
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    ll ans=INF;
    rep(mask,1<<n)
    {
        int ct=__builtin_popcount(mask);
        if(ct!=k) continue;

        vector<int> I,J;
        rep(i,n)
        {
            if(mask>>i&1) I.pb(i);
            else J.pb(i);
        }

        ll t=0;
        for(int i:I)for(int j:J) t+=abs(a[i]-a[j]);

        ans=min(ans,t);
    }

    cout << ans << endl;
    return 0;
}
