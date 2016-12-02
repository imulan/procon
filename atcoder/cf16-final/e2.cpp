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
    ll n,a;
    cin >>n >>a;

    ll ans=n;

    for(int k=1; k<=40; ++k)
    {
        ll l=0, r=1000000;
        while(r-l>1)
        {
            ll m=(l+r)/2;

            bool ok=false;
            ll val=1;
            rep(i,k+1)
            {
                val*=m;
                if(val>=n)
                {
                    ok=true;
                    break;
                }
            }

            if(ok) r=m;
            else l=m;
        }

        rep(i,k+1)
        {
            ll val=1;

            bool ok=false;
            rep(j,i)
            {
                val*=r-1;
                if(val>=n)
                {
                    ok=true;
                    break;
                }
            }
            if(!ok)
            {
                rep(j,k+1-i)
                {
                    val*=r;
                    if(val>=n)
                    {
                        ok=true;
                        break;
                    }
                }
            }

            if(ok)
            {
                ll tmp = a*k + i*(r-1) + (k+1-i)*r;
                ans=min(ans,tmp);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
