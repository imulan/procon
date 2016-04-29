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
	while(1)
	{
		int r,n;
		cin >>r >>n;

		if(r==0) break;

		map<int,int> f;
		for(int i=-20; i<=20; ++i) f[i]=0;

		rep(i,n)
		{
			int xl,xr,h;
			cin >>xl >>xr >>h;

			//最大値更新
			for(int j=xl; j<xr; ++j) f[j]=max(f[j],h);
		}

		//折り返す
		for(int i=0; i<=r; ++i) f[i]=min(f[i],f[-i-1]);

		double y=100;
		rep(i,r) y=min(y,f[i]-sqrt(r*r-i*i));

		printf("%.10lf\n",y+r);
	}
	return 0;
}
