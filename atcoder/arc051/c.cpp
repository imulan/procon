#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

ll modpow(ll p, ll x)
{
	ll ret=1;
	ll pw[35];
	pw[0]=p%mod;
	for(int i=1; i<=34; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

	rep(i,31)
	{
		if(x>>i&1) ret=(ret*pw[i])%mod;
	}

	return ret;
}

int main()
{
	int n;
	ll A,B;

	cin >>n >>A >>B;
	vector<ll> a(n);
	rep(i,n) cin >>a[i];

	sort(all(a));

	if(A==1) rep(i,n) std::cout << a[i] << std::endl;
	else
	{
		int ct=0;
		while(1)
		{
			if(a[0]*A>=a[n-1]) break;

			++ct;
			a[0]*=A;
			sort(all(a));
			if(ct==B) break;
		}

		if(ct==B) rep(i,n) std::cout << a[i] << std::endl;
		else
		{
			B-=ct;
			sort(all(a));

			int r=B%n;
			rep(i,n)
			{
				ll t=a[(i+r)%n];

				if(i+r>=n) t*=modpow(A,B/n+1);
				else t*=modpow(A,B/n);
				t%=mod;

				std::cout << t << std::endl;
			}

		}
	}

	return 0;
}
