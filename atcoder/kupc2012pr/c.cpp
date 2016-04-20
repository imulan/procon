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
	double h,v,g;

	//t=0でhが分かる
	printf("? %.12f\n", 0.0);
	fflush(stdout);
	scanf(" %lf", &h);

	double y1,y2;

	printf("? %.12f\n", sqrt(2));
	fflush(stdout);
	scanf(" %lf", &y1);
	y1-=h;

	printf("? %.12f\n", 2*sqrt(2));
	fflush(stdout);
	scanf(" %lf", &y2);
	y2-=h;

	g=(2*y1-y2)/2;
	v=y1+g;

	printf("! %.12f %.12f %.12f\n", h, v, g);
	fflush(stdout);
}
