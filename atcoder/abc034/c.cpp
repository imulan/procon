#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const long mod=1e9+7;

int main()
{
	long c[1010][1010];

	int i,j;
	rep(i,1002) c[i][0]=1;
	rep(i,1002) c[0][i]=1;

	for(i=1; i<=1000; ++i)
	for(j=1; j<=1000; ++j)
	c[i][j]=(c[i-1][j]+c[i][j-1])%mod;

	int w,h;
	cin >>w >>h;

	std::cout << c[h-1][w-1] << std::endl;
}
