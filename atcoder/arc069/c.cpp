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
    ll n,m;
    cin >>n >>m;

    ll l=0, r=n+m;

    while(r-l>1)
    {
        ll mid = (l+r)/2;

        bool ok=true;
        if(n>=mid) ok = (m>=mid*2);
        else
        {
            ll r_m = m - 2*(mid-n);
            ok = (r_m>=mid*2);
        }

        if(ok) l=mid;
        else r=mid;
    }

    cout << l << endl;
    return 0;
}
