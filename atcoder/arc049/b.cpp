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

struct p { int x,y,c; };

int main()
{
	int n;
	cin >>n;
	vector<p> v(n);
	rep(i,n) cin >>v[i].x >>v[i].y >>v[i].c;

	double left=0, right=1e8+1;
	double m;
	while(right-left>1e-6)
	{
		m=(left+right)/2;
		bool ok=true;
		//共通部分
		double lx=v[0].x-m/v[0].c, rx=v[0].x+m/v[0].c;
		double ly=v[0].y-m/v[0].c, ry=v[0].y+m/v[0].c;

		for(int i=1; i<n; ++i)
		{
			double ax=v[i].x-m/v[i].c, bx=v[i].x+m/v[i].c;
			double ay=v[i].y-m/v[i].c, by=v[i].y+m/v[i].c;

			//x方向
			if(rx<ax || bx<lx)
			{
				ok=false;
				break;
			}
			else
			{
				lx=max(lx,ax);
				rx=min(bx,rx);
			}

			//y方向
			if(ry<ay || by<ly)
			{
				ok=false;
				break;
			}
			else
			{
				ly=max(ly,ay);
				ry=min(by,ry);
			}
		}

		if(ok) right=m;
		else left=m;
	}

	printf("%.20lf\n",m);
	return 0;
}
