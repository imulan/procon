#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = 1000000000000000001LL;

int main()
{
    int n;
    ll K;
    cin >>n >>K;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    int X=n/2;
    int Y=n-X;

    vector<ll> p;
    rep(mask,1<<X)
    {
        ll m=1;
        rep(i,X)if(mask>>i&1)
        {
            if(m>INF/a[i])
            {
                m=INF;
                break;
            }
            m*=a[i];
        }
        p.pb(m);
    }

    sort(all(p));

    ll ans=0;
    rep(mask,1<<Y)
    {
        ll m=1;
        rep(i,Y)if(mask>>i&1)
        {
            if(m>INF/a[X+i])
            {
                m=INF;
                break;
            }
            m*=a[X+i];
        }

        int idx = upper_bound(all(p),K/m)-p.begin();
        ans += idx;
    }

    cout << ans-1 << endl;
    return 0;
}
