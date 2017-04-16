#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

int main()
{
    int n,T;
    scanf(" %d %d", &n, &T);
    vector<int> d(n);
    rep(i,n) scanf(" %d", &d[i]);
    sort(all(d));

    ll ans=1;
    int idx=0;
    for(int i=1; i<n; ++i)
    {
        while(idx<i && d[idx]<d[i]-T) ++idx;
        (ans*=(i-idx+1))%=mod;
    }

    printf("%lld\n", ans);
    return 0;
}
