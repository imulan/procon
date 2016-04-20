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
	double v;
	ll t;
	cin >>v >>t;

	ll vv=(v+0.000001)*10000;
	vv*=t;
	printf("%lld\n",vv/10000);
}
