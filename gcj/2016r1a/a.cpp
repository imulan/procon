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
	int T;
	cin >>T;
	rep(t,T)
	{
		string s;
		cin >>s;

		string ans="";
		rep(i,s.size())
		{
			string x=s[i]+ans;
			string y=ans+s[i];
			if(x<y) ans=y;
			else ans=x;
		}

		printf("Case #%d: ",t+1);
		std::cout << ans << std::endl;
	}
	return 0;
}
