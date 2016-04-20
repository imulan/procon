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
	int i;
	int n,Q;
	cin >>n >>Q;
	rep(i,Q)
	{
		int a,b,s,t;
		scanf(" %d %d %d %d",&a,&b,&s,&t);

		int ans=0;
		if(b<s || t<a) ans=t-s;
		else ans=max(0,a-s)+max(0,t-b);

		printf("%d\n",ans*100);
	}
}
