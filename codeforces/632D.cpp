#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define fi first
#define se second

int main()
{
	int n,m;
	cin >>n >>m;

	int ct[1000001]={0};
	vector<int> a(n);
	rep(i,n)
	{
		scanf(" %d",&a[i]);
		if(a[i]<=m)++ct[a[i]];
	}

	for(int i=m; i>=1; --i)
	{
		for(int j=2; i*j<=m; ++j) ct[i*j]+=ct[i];
	}


	int y=0;
	int x=-1;
	rep(i,m+1)
	{
		if(y<ct[i])
		{
			y=ct[i];
			x=i;
		}
	}

	if(y==0) printf("1 0\n");
	else
	{
		printf("%d %d\n",x,y);
		int ct=0;
		rep(i,n)
		{
			if(x%a[i]==0)
			{
				if(ct) printf(" ");
				printf("%d", i+1);
				++ct;
			}
		}
		printf("\n");
	}

}
