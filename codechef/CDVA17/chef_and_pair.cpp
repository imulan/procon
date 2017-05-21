#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll mypow(ll x, int n)
{
    ll ret=1;
    rep(i,n) ret*=x;
    return ret;
}

bool overflow(ll x, int n)
{
    ll t=1;
    ll LIM=1000000000000000000LL;

    rep(i,n)
    {
        if(t>LIM/x) return true;
        t*=x;
    }
    return false;
}

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        ll n;
        cin >>n;

        ll ct=1, s=n+1;
        for(int y=2; y<60; ++y)
        {
            if(mypow(2,y)>n) break;

            ll l=2,r=1000000001;
            while(r-l>1)
            {
                ll m=(l+r)/2;

                if(overflow(m,y))
                {
                    r=m;
                    continue;
                }

                if(mypow(m,y)<=n) l=m;
                else r=m;
            }

            if(mypow(l,y)==n)
            {
                if(y%2==0)
                {
                    ct+=2;
                    s+=2*y;
                }
                else
                {
                    ++ct;
                    s+=l+y;
                }
            }
        }

        printf("%lld\n%lld\n",ct,s);
    }
    return 0;
}
