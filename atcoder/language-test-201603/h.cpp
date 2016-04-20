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

	int T;
	cin >>T;
	rep(i,T)
	{
		int ta,tb,tc;
		cin >>ta >>tb >>tc;

		long double a=ta,b=tb,c=tc;
		if(a!=0)
		{
			long double D=b*b-4*a*c;
			if(D>0)
			{
				long double r=sqrt(D);
				long double x1=(-b-r)/2/a,x2=(-b+r)/2/a;
				if(x1>x2) swap(x1,x2);
				printf("2 %.15Lf %.15Lf\n",x1,x2);
			}
			else if(D==0) printf("1 %.15Lf\n",-b/2/a);
			else printf("0\n");
		}
		else
		{
			if(b!=0) printf("1 %.15Lf\n",-c/b);
			else
			{
				int ans=0;
				if(c==0) ans=3;
				printf("%d\n",ans);
			}
		}
	}
}
