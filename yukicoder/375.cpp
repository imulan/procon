#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll LIM=100000;

int main()
{
    ll n;
    cin >>n;

    ll tmin=n-1, tmax=n-1;
    for(ll i=1; i<=LIM; ++i)if(n%i==0)
    {
        ll m = n/i;
        for(ll j=i; j<=m/j; ++j)if(m%j==0)
        {
            ll k=m/j;
            tmin = min(tmin, i+j+k-3);
        }
    }

    cout << tmin << " " << tmax << endl;
    return 0;
}
