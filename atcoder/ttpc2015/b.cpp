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
	int n,b,c;
	cin >>n >>b >>c;
	vector<int> a(n);
	rep(i,n) cin >>a[i];

	int ans=0;
	for(int i=n-1; i>=0; --i)
	{
		if(c-b>=0)
		{
			ans+=a[i]*b;
			c-=b;
		}
		else
		{
			ans+=a[i]*c;
			break;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
