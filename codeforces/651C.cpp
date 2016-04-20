#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define x first
#define y second

typedef pair<long,long> point;

int main()
{
	long i;

	long n;
	cin >>n;
	std::vector<point> p(n);
	rep(i,n) scanf(" %ld %ld", &p[i].x, &p[i].y);

	//それぞれの座標にいる数
	map<long,ll> X,Y;
	//同じ座標にいる数
	map<point,ll> ct;

	rep(i,n)
	{
		if(X.find(p[i].x)==X.end()) X[p[i].x]=1;
		else ++X[p[i].x];

		if(Y.find(p[i].y)==Y.end()) Y[p[i].y]=1;
		else ++Y[p[i].y];

		if(ct.find(p[i])==ct.end()) ct[p[i]]=1;
		else ++ct[p[i]];
	}

	ll ans=0;
	rep(i,n)
	{
		ans += X[p[i].x]-1 + Y[p[i].y]-1 - (ct[p[i]]-1);
	}
	ans/=2;

	std::cout << ans << std::endl;
}
