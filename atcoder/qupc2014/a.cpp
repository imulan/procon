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
	int a,b,c,d,e[10][10];

	cin >>a >>b >>c >>d;
	rep(i,c)rep(j,a) cin >>e[i][j];

	int ans=100;
	while(ans>0)
	{
		int ct=0;
		rep(i,c)
		{
			int t=0;
			rep(j,a) t+=(e[i][j]>=ans);

			ct+=(t>=b);
		}
		if(ct>=d) break;
		--ans;
	}

	std::cout << ans << std::endl;
	return 0;
}
