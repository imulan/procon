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

const int N=10000;

int main()
{
	bool p[N+1];
	fill(p,p+N+1,true);
	p[0]=p[1]=false;
	for(int i=2; i<=N; ++i)
	{
		if(p[i]) for(int j=2;i*j<=N;++j) p[i*j]=false;
	}

	int n, ans=0;
	cin >>n;
	rep(i,n) ans+=p[i];

	std::cout << ans << std::endl;
	return 0;
}
