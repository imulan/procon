#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const int N=2000000;

int main()
{
	int i,j;

	//素数列挙
	bool prime[N+1];
	fill(prime,prime+N+1,true);
	prime[0]=prime[1]=false;
	for(i=2;i<=N;++i)
	{
		if(prime[i]) for(j=2;i*j<=N;++j) prime[i*j]=false;
	}

	//素数のリストの作成
	vector<int> p;
	rep(i,N+1) if(prime[i]) p.pb(i);

	//for(i=0; p[i]<=2000; ++i) printf(" %d: %d\n",i,p[i]);

	int n,k;
	cin >>n >>k;

	int ans=0;
	for(i=2; i<=n; ++i)
	{
		int t=i;
		int ct=0;
		for(j=0; p[j]*p[j]<=i; ++j)
		{
			if(t%p[j]==0)
			{
				++ct;
				while(t%p[j]==0) t/=p[j];
			}
		}

		if(prime[t]) ++ct;
		if(ct>=k) ++ans;
	}

	std::cout << ans << std::endl;
}
