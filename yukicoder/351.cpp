#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<char,int> p;

int main()
{
	int i;

	int h,w,n;
	cin >>h >>w >>n;

	vector<p> v(n);
	rep(i,n) scanf(" %c %d",&v[i].fi,&v[i].sc);

	int x=0,y=0;
	for(i=n-1; i>=0; --i)
	{
		char s=v[i].fi;
		int k=v[i].sc;

		if(s=='R' && k==x) y=(y+w-1)%w;
		else if(s=='C' && k==y) x=(x+h-1)%h;

		//printf(" %d %d\n",x,y);
	}

	string ans="white";
	if((x+y)%2==1) ans="black";
	std::cout << ans << std::endl;
}
