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

int main()
{
	int n,q;
	cin >>n >>q;

	map<string,string> m;
	rep(i,q)
	{
		string s,t;
		cin >>s >>t;
		m[s]=t;
	}

	int ans=0;
	string z="abcdef";

	int lim=1;
	rep(i,n)lim*=6;

	rep(i,lim)
	{
		int now=i;
		int a[6]={0};
		rep(j,n){
			a[j]=now%6;
			now/=6;
		}

		string b="";
		rep(j,n) b+=z[a[j]];
		reverse(all(b));

		while(b.size()>1)
		{
			bool found=false;
			rep(j,q)
			{
				if(m.find(b.substr(0,2))!=m.end())
				{
					found=true;
					b=m[b.substr(0,2)]+b.substr(2);
				}
			}

			if(!found) break;
		}

		if(b=="a") ++ans;
	}

	std::cout << ans << std::endl;
	return 0;
}
