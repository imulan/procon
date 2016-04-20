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

ll modmul(ll x, ll y)
{
	return (x*y)%mod;
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
	rep(i,32)
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
	ll x,y,z;
	cin >>x >>y >>z;

	ll xy=modmul(x,y);
	ll yz=modmul(y,z);
	ll zx=modmul(z,x);

	ll r=(yz-zx+mod)%mod;
	r*=modinv((xy-yz+zx+mod)%mod);
	r%=mod;

	ll c=(yz-xy+mod)%mod;
	c*=modinv((xy-yz+zx+mod)%mod);
	c%=mod;

	cout <<r<<" "<<c <<endl;
}
