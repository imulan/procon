#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const ll mod=1e9+7;

ll modfact(ll x)
{
	ll t=1;
	for(ll i=1;i<=x;++i)
	{
		t*=i;
		t%=mod;
	}

	return t;
}

ll modinv(ll x)
{
	ll i;
	ll p=mod-2;

	ll pw[60];
	pw[0]=x;
	rep(i,60-1)
	{
		pw[i+1]=pw[i]*pw[i];
		pw[i+1]%=mod;
	}

	ll ret=1;
	rep(i,35)
	{
		if(p>>i&1)
		{
			ret*=pw[i];
			ret%=mod;
		}
	}

	return ret;
}

int main()
{
	ll w,h;
	cin >>w >>h;

	--w;
	--h;

	ll x=modfact(w+h);
	ll y=modinv(modfact(w));
	ll z=modinv(modfact(h));

	ll ans=x*y;
	ans%=mod;
	ans*=z;
	ans%=mod;
	std::cout << ans << std::endl;
}
