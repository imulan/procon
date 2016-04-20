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
	int T=1000000;

	int n;
	cin >>n;

	long double ans=0;
	rep(i,T)
	{
		ll c=1;
		int now[20];
		now[0]=1;

		for(j=2;j<=n;++j)
		{
			int m=j-1;
			int r=rand()%(m+1);

			if(r==0)
			{
				for(int k=n;k>0;--k) now[k]=now[k-1];
				now[0]=j;
				++c;
			}
			else if(r==m)
			{
				now[j-1]=j;
				++c;
			}
			else
			{
				int x=now[r-1];
				int y=now[r];
				c+=x*y;

				for(int k=n;k>r;--k) now[k]=now[k-1];
				now[r]=j;
			}

		}

		/*
		std::cout << now << std::endl;
		std::cout << c << std::endl;
		*/
		ans += (long double)c/T;
	}

	printf("%.10Lf\n",ans);
}
