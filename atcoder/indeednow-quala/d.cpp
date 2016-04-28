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

inline int ab(int x)
{
	return (x>0)?x:-x;
}

int main()
{
	int h,w;
	int c[6][6];

	cin >>h >>w;
	rep(i,h)rep(j,w) cin >>c[i][j];

	int ans=0;

	for(int i=1; i<h*w; ++i)
	{
		int f=(i-1)/w, s=(i-1)%w;

		rep(y,h)rep(x,w)
		{
			if(c[y][x]==i)
			{
				ans+=ab(y-f)+ab(x-s);
				break;
			}
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
