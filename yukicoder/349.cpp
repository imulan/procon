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

	int n;
	cin >>n;
	map<string,int> m;
	rep(i,n)
	{
		string a;
		cin >>a;
		if(m.find(a)==m.end()) m[a]=1;
		else ++m[a];
	}

	int x=0;
	each(it,m) x=max(x,it->sc);
	//std::cout << x << std::endl;
	string ans="NO";
	if(x<=(n+1)/2) ans="YES";
	std::cout << ans << std::endl;
}
