#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<int,int> pi;

pi f(int n)
{
	int x=0,y=0;

	while(x*(x+1)/2<n) ++x;
	y=n-(x-1)*x/2;
	x=x+1-y;
	//printf(" %d:: %d %d\n",n,x,y);
	return pi(x,y);
}

int main()
{
	int a,b;
	cin >>a >>b;

	pi x=f(a);
	pi y=f(b);

	int p=x.fi+y.fi, q=x.sc+y.sc;
	//printf(" p,q : %d,%d\n",p,q);

	int n=p+q-1;
	int ans=(n-1)*n/2+q;
	std::cout << ans << std::endl;
}
