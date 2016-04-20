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
	int a,b;
	cin >>a >>b;

	long ans=0;
	while(1)
	{
		if(a<=1&&b<=1) break;

		if(a<b)
		{
			++a;
			b-=2;
		}
		else
		{
			a-=2;
			++b;
		}
		++ans;
		//printf(" %ld :%d,%d\n",ans,a,b);

		if(a<=0||b<=0) break;
	}

	std::cout << ans << std::endl;
}
