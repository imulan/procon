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
	int n,a,b;
	cin >>n >>a >>b;

	if(a*b<n) printf("-1\n");
	else
	{
		int f[100][100]={0};

		int m=1;
		int ct=1;
		int r=0,c=0;
		while (ct<=n)
		{
			f[r][c]=ct++;
			c+=m;

			if(c==b)
			{
				m=-1;
				++r;
				c=b-1;
			}
			else if(c==-1)
			{
				m=1;
				++r;
				c=0;
			}
		}

		rep(i,a)
		{
			rep(j,b)
			{
				if(j) printf(" ");
				printf("%d",f[i][j]);
			}
			printf("\n");
		}
	}
	
}
