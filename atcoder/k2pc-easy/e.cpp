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
	ll n,s=-1;
	cin >>n;

	//nは2か平方数じゃないとダメ
	bool valid=false;
	for(ll i=2; i<=1000000; ++i)
	{
		if(i*i==n)
		{
			s=i;
			valid=true;
			break;
		}
	}

	if(n==2)
	{
		printf("0\n");
		return 0;
	}
	else if(!valid)
	{
		printf("-1\n");
		return 0;
	}

	//solve
	ll ans=n-2+s-1;
	//i->(i-1)^2にあげる作業
	for(ll i=s; i>2; --i)ans+=(i-1)*(i-1)-i;
	std::cout << ans << std::endl;
	
	return 0;
}
