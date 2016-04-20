#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main()
{
	int i;

	string s;
	cin >>s;

	string ans="";
	int ct=0;
	rep(i,s.size())
	{
		if((ct%2==0 && s[i]=='A')||(ct%2==1 && s[i]=='Z'))
		{
			ans+=s[i];
			++ct;
		}
	}

	if(ans.size()<2) ans="-1";
	else if(ans.size()%2==1) ans.resize(ans.size()-1);
	std::cout << ans << std::endl;
}
