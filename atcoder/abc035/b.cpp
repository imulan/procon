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

inline int ab(int x)
{
	return (x>0)?x:-x;
}

int main()
{
	string s;
	int t;

	int x=0, y=0, q=0;
	cin >>s >>t;
	rep(i,s.size())
	{
		if(s[i]=='U') ++y;
		else if(s[i]=='D') --y;
		else if(s[i]=='L') --x;
		else if(s[i]=='R') ++x;
		else ++q;
	}

	int ans=-1;
	if(t==1) ans=ab(x)+ab(y)+q;
	else
	{
		rep(i,q)
		{
			if(ab(x)<ab(y))
			{
				if(y>0) --y;
				else ++y;
			}
			else
			{
				if(x>0) --x;
				else ++x;
			}
		}

		ans=ab(x)+ab(y);
	}

	std::cout << ans << std::endl;
	return 0;
}
