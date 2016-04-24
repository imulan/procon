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
	double p;
	ll n;
	cin >>p >>n;

	double pw[61];
	pw[0]=1-2*p;
	for(int i=1; i<=60; ++i) pw[i]=pw[i-1]*pw[i-1];

	double ret=1;
	rep(i,61)
	{
		if(n>>i&1) ret*=pw[i];
	}

	printf("%.20lf\n",(1-ret)/2);
	return 0;
}
