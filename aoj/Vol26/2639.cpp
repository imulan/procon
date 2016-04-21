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
	int a,b,c;
	cin >>a >>b >>c;

	int s=a+b;
	int ans=0;

	//いつかはおりられるので１つずつ探索
	rep(t,5000000)
	{
		int now=60*t+c;
		if(now%s<=a)
		{
			ans=now;
			break;
		}

	}

	if(ans==0) ans=-1;

	std::cout << ans << std::endl;
	return 0;
}
