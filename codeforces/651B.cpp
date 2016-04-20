#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main()
{
	long i,j;

	long n;
	cin >>n;

	long ct[1001]={0};
	rep(i,n)
	{
		long a;
		cin >>a;
		++ct[a];
	}

	vector<long> b;
	for(i=1;i<=1000;++i)
	{
		for(j=1;j<=1000;++j)
		{
			if(ct[j]>0)
			{
				b.pb(j);
				--ct[j];
			}
		}
	}

	//rep(i,n) printf(" %ld\n", b[i]);

	long ans=0;
	rep(i,n-1)
	{
		if(b[i+1]>b[i]) ++ans;
	}
	std::cout << ans << std::endl;
}
