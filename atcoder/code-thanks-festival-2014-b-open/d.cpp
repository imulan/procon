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
	int i,j;

	int n,t;
	cin >>n >>t;

	int ct[1001]={0};
	rep(i,n)
	{
		int a;
		cin >>a;
		for(j=1; a*j<=t; ++j) ++ct[a*j];
	}

	int ans=0;
	rep(i,t+1) ans=max(ans,ct[i]);

	std::cout << ans << std::endl;
}
