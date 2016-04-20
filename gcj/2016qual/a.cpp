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

int main()
{
	int T;
	cin >>T;
	rep(t,T)
	{
		ll n;
		cin >>n;

		printf("Case #%d: ",t+1);

		if(n==0) printf("INSOMNIA\n");
		else
		{
			int mask=0;
			ll add=n;
			while(1)
			{
				ll t=n;
				while(t>0)
				{
					int d=t%10;
					mask|=(1<<d);
					t/=10;
				}

				if(mask==1023) break;
				else n+=add;
			}

			std::cout << n << std::endl;
		}
	}

	return 0;
}
