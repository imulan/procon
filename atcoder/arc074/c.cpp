#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll solve(ll h, ll w)
{
    ll ret = LLONG_MAX;

    if(h>=3)
    {
        if(h%3==0) ret=min(ret,0LL);
        else ret=min(ret,w);
    }
    if(w>=3)
    {
        if(w%3==0) ret=min(ret,0LL);
        else ret=min(ret,h);
    }
    for(ll i=1; i<=w-1; ++i)
    {
        ll a = h*i;
        ll b = (w-i)*(h/2);
        ll c = (w-i)*(h-h/2);
        ret = min(ret, max({a,b,c})-min({a,b,c}));
    }
    for(ll i=1; i<=h-1; ++i)
    {
        ll a = w*i;
        ll b = (h-i)*(w/2);
        ll c = (h-i)*(w-w/2);
        ret = min(ret, max({a,b,c})-min({a,b,c}));
    }

    return ret;
}

int main()
{
    ll h,w;
    cin >>h >>w;
    cout << solve(h,w) << endl;
    return 0;
}
